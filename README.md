# CMS079-ijl15

移植与https://github.com/BeiDouMS/BeiDou-ijl15

主要是为了移植https://github.com/Chronicle20/gms-83-dll 这个框架

代码未清理，除了启用的功能能外，其他基址还是083的


## 使用方法
已测试的开发工具 VS 2022，SDK 10，工具集 VS2022（v144）

使用VS打开的时候注意，要使用 Release x86 MT/MD 模式生成解决方案

- MT 无需C++运行库，不支持HOOK模式启动
- MD 需要C++运行库，支持HOOK模式启动

生成后可在 out相应的Release-mt/md 目录下找到 ijl15.dll

支持两种模式

### 直接加载模式：
直接覆盖客户端的ijl15.dll,并修改配置文件中ijl15hook为false

### HOOK模式:
先把客户端原本的ijl15.dll重命名成2ijl15.dll，然后把生成的ijl15.dll拷贝到客户端目录下，ijl15hook为true

两种模式均需要把项目根目录下的config.ini同样复制到客户端目录下，具体配置都在config.ini中

具体功能查看配置文件

## 主要额外添加的特殊功能

- 双击跳跃键使用二段跳
- 屏蔽了聊天室按钮弹窗仅发数据包（可用作解卡）
- 角色等级突破Short类型，角色经验突破为Long类型
- 伤害皮肤
- 简单的内存防炸

### 伤害皮肤说明:

伤害皮肤的[DamageSkin.img](https://github.com/Willh92/079-ijl15/releases/download/1.0.0/DamageSkin.img)文件放在Effect下

格式为：{皮肤ID}/NoRed0   皮肤ID=0为默认皮肤 具体参考下载文件

#### 本地版本：

DamageSkin={皮肤ID}，直接开起，仅自己可见

#### 远程版本：

RemoteDamageSkin=true,服务器需要做相应的处理,主要hook了家族名称数据包做对应加载

假设GuildName为 `途插天下第一`皮肤ID为 `2`
则对应发送数据包GuildName变为`途插天下第一$$2`

GuildName不存在的时候用`#`替代变为`#$$2`

1. `client.MapleStat`添加 `DAMAGESKIN(4194304)` 枚举类型
2. `tools.MaplePacketCreator.MaplePacketCreator.updatePlayerStats`添加`DAMAGESKIN`处理为`writeInt`

#### 更新皮肤的参考代码如下

```Java
//handling.channel.handler.InterServerHandler
public static void LoggedIn(int playerid, MapleClient c) {
     //……省略
     player.sendDamageSkin();  //发送伤害皮肤包
     player.sendMacros();
      //……省略
}

//client.MapleCharacter
public void sendDamageSkin() {
    updateSingleStat(MapleStat.DAMAGESKIN, this.damageSkin);
}

//tools.MaplePacketCreator
public static byte[] updatePlayerStats(Map<MapleStat, Number> mystats, boolean itemReaction, MapleCharacter chr) {
    //……省略
                case DAMAGESKIN:
                    mplew.writeInt(statupdate2.getValue().intValue());
                    continue;
    //……省略
}

//tools.MaplePacketCreator
public void updateDamageSkin(int damageSkin) {
        this.damageSkin = damageSkin;
        MapleMap map = getMap();
        if (map != null) {
            String guildName = null;
            MapleGuild gs = World.Guild.getGuild(getGuildId());
            if (gs != null) {
                guildName = gs.getName();
            }
            if (guildName == null || guildName.length() == 0) {
                guildName = "#";
            }
            getMap().broadcastMessage(this, MaplePacketCreator.guildNameChanged(getId()
                    , guildName + "$$" + damageSkin), false);
        }
        updateSingleStat(MapleStat.DAMAGESKIN, damageSkin);
    }

public static byte[] spawnPlayerMapobject(MapleCharacter chr) {
        //……省略
        //找到对应代码块修改
        if (chr.getGuildId() <= 0) {
            mplew.writeMapleAsciiString("#$$" + chr.getDamageSkin());
            mplew.writeZeroBytes(6);
        } else {
            MapleGuild gs = World.Guild.getGuild(chr.getGuildId());
            if (gs != null) {
                mplew.writeMapleAsciiString(gs.getName() + "$$" + chr.getDamageSkin());
                mplew.writeShort(gs.getLogoBG());
                mplew.write(gs.getLogoBGColor());
                mplew.writeShort(gs.getLogo());
                mplew.write(gs.getLogoColor());
            } else {
                mplew.writeMapleAsciiString("#$$" + chr.getDamageSkin());
                mplew.writeZeroBytes(6);
            }
        }
        //……省略
```

# 仅供学习交流使用!!!
