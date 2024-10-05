#include "stdafx.h"
#include "AddyLocations.h"
#include "codecaves.h"
#include <cstringt.h>
#include "FixIme.h"
#include "FixBuddy.h"

bool Client::isImg = true;
int Client::m_nGameHeight = 720;
int Client::m_nGameWidth = 1280;
int Client::MsgAmount = 26;
bool Client::CustomLoginFrame = true;
bool Client::WindowedMode = true;
bool Client::RemoveLogos = true;
int Client::setDamageCap = 199999;
int Client::setMAtkCap = 1999;
int Client::setAccCap = 999;
int Client::setAvdCap = 999;
double Client::setAtkOutCap = 199999;
bool Client::longEXP = false;
bool Client::useTubi = false;
bool Client::bigLoginFrame = false;
bool Client::SwitchChinese = false;
int Client::speedMovementCap = 140;
bool Client::noPassword = false;
bool Client::debug = false;
bool Client::climbSpeedAuto = false;
bool Client::canInjected = false;
bool Client::injected = false;
bool Client::ServerIP_Address_hook = true;
bool Client::ijl15hook = false;
float Client::climbSpeed = 1.0;
unsigned char Client::imeType = 1;
std::string Client::ServerIP_AddressFromINI = "127.0.0.1";
int Client::serverIP_Port = 8484;
bool Client::talkRepeat = false;
int Client::talkTime = 2000;
int Client::StatBackgrndWidth = 176;
int Client::StatDetailBackgrndWidth = 177;
int Client::StatDetailBackgrndWidthRect = 200;

bool Client::s14101004 = true;
bool Client::s4221001 = false;
bool Client::s4221007 = false;

void Client::UpdateGameStartup() {
	//Memory::CodeCave(cc0x0044E550, dw0x0044E550, dw0x0044E550Nops); //run from packed client //skip //sub_44E546
	//Memory::CodeCave(cc0x0044E5BE, dw0x0044E5BE, dw0x0044E5BENops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044E5DB, dw0x0044E5DB, dw0x0044E5DBNops); //run from packed client //skip //sub_44E5D5 (defined function)
	//Memory::CodeCave(cc0x0044E6AC, dw0x0044E6AC, dw0x0044E6ACNops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044E71D, dw0x0044E71D, dw0x0044E71DNops); //run from packed client //skip //sub_44E716 (defined function)
	//Memory::CodeCave(cc0x0044E80C, dw0x0044E80C, dw0x0044E80CNops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044E8B4, dw0x0044E8B4, dw0x0044E8B4Nops); //run from packed client //skip //sub_44E88E
	//Memory::CodeCave(cc0x0044EA22, dw0x0044EA22, dw0x0044EA22Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044EA6F, dw0x0044EA6F, dw0x0044EA6FNops); //run from packed client //skip //sub_44EA64
	//Memory::CodeCave(cc0x0044EBD6, dw0x0044EBD6, dw0x0044EBD6Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044ECA1, dw0x0044ECA1, dw0x0044ECA1Nops); //run from packed client //skip //sub_44EC9C
	//Memory::CodeCave(cc0x0044ED32, dw0x0044ED32, dw0x0044ED32Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x0044ED52, dw0x0044ED52, dw0x0044ED52Nops); //run from packed client //skip	//sub_44ED47
	//Memory::CodeCave(cc0x0044EED3, dw0x0044EED3, dw0x0044EED3Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00494943, dw0x00494943, dw0x00494943Nops); //run from packed client //skip //sub_494931
	//Memory::CodeCave(cc0x00494BB6, dw0x00494BB6, dw0x00494BB6Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00494CA9, dw0x00494CA9, dw0x00494CA9Nops); //run from packed client //skip //sub_494CA3
	//Memory::CodeCave(cc0x00494CF0, dw0x00494CF0, dw0x00494CF0Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00494D3B, dw0x00494D3B, dw0x00494D3BNops); //long jmp //??CClientSocket::Connect=sub_494D2F-494ECE //CClientSocket::Connect: Skip IP checks by changing short jmp at beginning of the method to long jmp that goes to the client socket code
	//Memory::CodeCave(cc0x00494EAF, dw0x00494EAF, dw0x00494EAFNops); //run from packed client //skip	//??CClientSocket //??

	//Memory::CodeCave(cc0x00494EEC, dw0x00494EEC, dw0x00494EECNops); //run from packed client //skip //sub_494ED1
	//Memory::CodeCave(cc0x00494F87, dw0x00494F87, dw0x00494F87Nops); //run from packed client //skip

	//Memory::CodeCave(ccCLoginSendCheckPasswordPacket, dwCLoginSendCheckPasswordPacket, CLoginSendCheckPasswordPacketNops); //CLogin::SendCheckPasswordPacket: At the start of the sequence of pushes that contains 0C9h, place a long jmp to further down in the method to the SystemInfo basic block.Do auth patches for encoding the correct strings(user / pw)
	//Memory::WriteByte(0x005F6B87 + 2, 0x08); //CLogin::SendCheckPasswordPacket/sub_5F6952 //??
	//Memory::WriteByte(0x005F6BA0 + 2, 0xA0); //CLogin::SendCheckPasswordPacket //??
	//unsigned char CA_005F6BA4[] = { 0xFF, 0x75, 0x0C, 0x90, 0x90, 0x90, 0x90 }; //CLogin::SendCheckPasswordPacket //??
	//Memory::WriteByteArray(0x005F6BA4, CA_005F6BA4, sizeof(CA_005F6BA4)); //CLogin::SendCheckPasswordPacket //??

	//Memory::FillBytes(0x009F1C04, 0x90, 5);//run from packed client //WinMain: nop ShowStartUpWndModal
	//Memory::WriteByte(0x009F242F, 0xEB); //run from packed client //WinMain: jz->jmp for ShowADBalloon code (pretty much at the end of method, above push with small number)

	//Memory::CodeCave(cc0x009F4E84, dw0x009F4E84, dw0x009F4E84Nops); //run from packed client //skip	//sub_9F4E54
	//Memory::CodeCave(cc0x009F4EC3, dw0x009F4EC3, dw0x009F4EC3Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x009F4F12, dw0x009F4F12, dw0x009F4F12Nops); //run from packed client //skip	//sub_9F4F09 (defined function)
	//Memory::CodeCave(cc0x009F4FC6, dw0x009F4FC6, dw0x009F4FC6Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x009F503C, dw0x009F503C, dw0x009F503CNops); //run from packed client //skip	//sub_9F4FDA
	//Memory::CodeCave(cc0x009F51A7, dw0x009F51A7, dw0x009F51A7Nops); //run from packed client //skip	//??CWvsApp::CallUpdate

	//Memory::CodeCave(cc0x009F526F, dw0x009F526F, dw0x009F526FNops); //run from packed client //long jump //sub_9F5239-9F5C4F
	//Memory::CodeCave(cc0x009F5653, dw0x009F5653, dw0x009F5653Nops); //run from packed client //skip
	//Memory::CodeCave(cc0x009F5833, dw0x009F5833, dw0x009F5833Nops); //run from packed client //long jump
	//Memory::CodeCave(cc0x009F5C2C, dw0x009F5C2C, dw0x009F5C2CNops); //run from packed client //skip

	//Memory::CodeCave(cc0x009F5CA3, dw0x009F5CA3, dw0x009F5CA3Nops); //dwCWvsAppRun=sub_9F5C50-9F698D CWvsApp::Run: After CClientSocket::ManipulatePacket, long jmp to "push 0FFh push 0 push 0"
	//Memory::CodeCave(cc0x009F5FBD, dw0x009F5FBD, dw0x009F5FBDNops); //run from packed client	//dwCWvsAppRun	//??
	//unsigned char CA_009F62E2[] = { 0x8B, 0x0D, 0xA8, 0xC3, 0xBE, 0x00,  0x90, 0x90, 0x90, 0x90, 0x90 }; //CWvsApp::Run: nop?
	//Memory::WriteByteArray(0x009F62E2, CA_009F62E2, sizeof(CA_009F62E2)); //dwCWvsAppRun //CWvsApp::Run: nop call to CSecurityClient::Update while we're at it
	//Memory::CodeCave(cc0x009F631C, dw0x009F631C, dw0x009F631CNops); //run from packed client	//dwCWvsAppRun	//??
	//Memory::CodeCave(cc0x009F691F, dw0x009F691F, dw0x009F691FNops); //dwCWvsAppRun //CWvsApp::Run: Below IWzGr2D::RenderFrame (where it does 0-100 rand stuff), place long jmp to push 1; call Sleep way down in the method
	////??CWvsApp::Run: At the end of the method, there's a call to _free, followed by add esp, 4, followed by a cmp ..., 12h. Skip the free by jmping straight to the cmp.

	//Memory::CodeCave(cc0x009F6F36, dw0x009F6F36, dw0x009F6F36Nops); //run from packed client //skip	//sub_9F6F27
	//Memory::CodeCave(cc0x009F6F5C, dw0x009F6F5C, dw0x009F6F5CNops); //run from packed client //skip	//near closesocket down

	//Memory::CodeCave(cc0x009F7CFA, dw0x009F7CFA, dw0x009F7CFANops); //run from packed client //skip //sub_9F7CE1 
	//Memory::CodeCave(cc0x009F7D83, dw0x009F7D83, dw0x009F7D83Nops); //run from packed client //long jump //??CWvsApp::InitializeInput
	//Memory::CodeCave(cc0x009F81FB, dw0x009F81FB, dw0x009F81FBNops); //run from packed client //skip //sub_9F7CE1 

	//Memory::CodeCave(cc0x009F84E9, dw0x009F84E9, dw0x009F84E9Nops); //run from packed client //skip //sub_9F84D0
	//Memory::CodeCave(cc0x009F8AD4, dw0x009F8AD4, dw0x009F8AD4Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00A4BB39, dw0x00A4BB39, dw0x00A4BB39Nops); //run from packed client //skip //sub_A4BB2B
	//Memory::CodeCave(cc0x00A4BC79, dw0x00A4BC79, dw0x00A4BC79Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00A4BD05, dw0x00A4BD05, dw0x00A4BD05Nops); //run from packed client //skip //sub_A4BCFF
	//Memory::CodeCave(cc0x00A4BD4E, dw0x00A4BD4E, dw0x00A4BD4ENops); //run from packed client //skip

	//Memory::CodeCave(cc0x00A4BD99, dw0x00A4BD99, dw0x00A4BD99Nops); //run from packed client //skip //sub_A4BD91
	//Memory::CodeCave(cc0x00A4BDE3, dw0x00A4BDE3, dw0x00A4BDE3Nops); //run from packed client //skip

	//Memory::CodeCave(cc0x00A4BDFE, dw0x00A4BDFE, dw0x00A4BDFENops); //run from packed client //skip //sub_A4BDF8
	//Memory::CodeCave(cc0x00A4BE47, dw0x00A4BE47, dw0x00A4BE47Nops); //run from packed client //skip

	//unsigned char CA_00E93220[] = { 0x00, 0x00, 0x00, 0x43, 0x6F, 0x43, 0x72, 0x65,  0x61, 0x74, 0x65, 0x47, 0x75, 0x69, 0x64, 0x00 }; //run from packed client //addr 00E93220 //??
	//Memory::WriteByteArray(0x00E93220, CA_00E93220, sizeof(CA_00E93220)); //run from packed client //addr 00E93220 //??

	//Memory::FillBytes(0x00C08459, 0x20, 0x00C0846E - 0x00C08459);//remove elevation requests
	//Memory::WriteByte(0x00C08459, 0x22);//remove elevation requests	//thanks stelmo for showing me how to do this
	//Memory::WriteString(0x00C08459 + 1, "asInvoker");//remove elevation requests	//not working from dll
	//Memory::WriteByte(0x00C08463, 0x22);//remove elevation requests	//thanks stelmo for showing me how to do this
	//Memory::WriteByte(0x0049C2CD + 1, 0x01);//remove elevation requests	//still not working unfortunately	//still keeping this to checks for admin privilege
	//Memory::WriteByte(0x0049CFE8 + 1, 0x01);//likely requires affecting WINAPI CreateProcess, which requires a launcher		//because a packed client cannot be directly edited for these offsets
	//Memory::WriteByte(0x0049D398 + 1, 0x01);//remove elevation requests	//still not working unfortunately

	////optional non-resolution related stuff
	if (useTubi) { Memory::FillBytes(0x00485173, 0x90, 2); }

	Memory::WriteInt(0x007868CF + 1, 2147483646); // 物攻PAD 相关具体不明，默认值1999，int 4字节
	Memory::WriteInt(0x007869A9 + 1, 2147483646); // 技能 相关具体不明，默认值1999，int 4字节
	Memory::WriteInt(0x008C8BAE + 1, setDamageCap); // 物攻面板，默认值199999，int 4字节
	Memory::WriteInt(0x00786A8F + 1, setMAtkCap); // 魔攻面板，int 4字节
	Memory::WriteInt(0x0078876B + 1, setMAtkCap); // 魔攻面板，int 4字节
	Memory::WriteInt(0x0078881B + 1, setAccCap); // 命中，默认999
	Memory::WriteInt(0x0078884D + 1, setAvdCap); // 回避，默认999
	Memory::WriteInt(0x0079617F + 1, 2147483646); // 计算物理伤害相关，意义不明，默认1999，int 4字节
	Memory::WriteInt(0x00796BF2 + 1, 2147483646); // 计算魔攻MDamage的，默认值1999，int 4字节，注意：这里不改的话，打怪输出计算的魔法伤害就是按1999计算的
	Memory::WriteInt(0x007971CC + 1, 2147483646); // 计算魔攻MDamage的，默认值1999，int 4字节，注意：这里不改似乎也不影响输出计算
	Memory::WriteInt(0x007942B1 + 1, 2147483646); //CalcDamage::PDamage 999，意义不明，int 4字节
	Memory::WriteInt(0x007948AF + 1, 2147483646); //CalcDamage::PDamage 999，意义不明，int 4字节
	Memory::WriteInt(0x00796DE6 + 1, 2147483646); //CalcDamage::MDamage 999，意义不明，int 4字节

	Memory::WriteDouble(0x00B064B8, setAtkOutCap);	// 输出显示上限，默认199999，double 8字节


	Memory::WriteInt(0x0078888E + 3, speedMovementCap); //set speed cap //ty ronan
	Memory::WriteInt(0x008C9B1A + 1, speedMovementCap); //set speed cap //ty ronan
	Memory::WriteInt(0x008C9900 + 1, speedMovementCap); //set speed cap //ty ronan

	Memory::WriteInt(0x0075F142 + 1, serverIP_Port);
	Memory::WriteByte(0x009FC0CB, 0xEB);	//jz 009FC13A ; jmp remove exit ads
	Memory::CodeCave(unlockPacket, 0x007DADB8, 5);
}

void Client::UpdateResolution() {

	if (m_nGameWidth <= 800) {
		Memory::WriteInt(dwQuickSlotInitHPos + 1, 580); //push 647 //hd800
		Memory::WriteInt(dwQuickSlotHPos + 1, 580); //push 647 //hd800
		Memory::WriteInt(dwQuickSlotCWndHPos + 2, -580); //lea ebx,[eax-647]
		Memory::WriteInt(0x008E4448 + 1, 587);  //装备按鈕寬度
		Memory::WriteInt(0x008E53FB + 1, 587);  //装备闪烁寬度
		Memory::WriteInt(0x008E44C5 + 1, 621);  //背包按鈕寬度
		Memory::WriteInt(0x008E549E + 1, 621);  //背包闪烁寬度
		Memory::WriteInt(0x008E4542 + 1, 587);  //能力值按鈕寬度
		Memory::WriteInt(0x008E5358 + 1, 587);  //能力值闪烁图标宽度
		Memory::WriteInt(0x008E45BF + 1, 621);  //技能按鈕寬度
		Memory::WriteInt(0x008E5157 + 1, 621);  //技能按鈕寬度
		return;
	}

	nStatusBarY = Client::m_nGameHeight - 578;

	Memory::CodeCave(AdjustStatusBar, dwStatusBarVPos, 5);
	Memory::CodeCave(AdjustStatusBarBG, dwStatusBarBackgroundVPos, 5);
	Memory::CodeCave(AdjustStatusBarInput, dwStatusBarInputVPos, 11);

	Memory::WriteInt(dwApplicationHeight + 1, m_nGameHeight);//push 600
	Memory::WriteInt(dwApplicationWidth + 1, m_nGameWidth);	//push 800 ; CWvsApp::InitializeGr2D
	Memory::WriteInt(dwCursorVectorVPos + 2, (unsigned int)floor(-m_nGameHeight / 2));//push -300				!!moves all interactable UI elements!!
	Memory::WriteInt(dwCursorVectorHPos + 2, (unsigned int)floor(-m_nGameWidth / 2));	//push -400 ; CInputSystem::SetCursorVectorPos				!!moves all interactable UI elements!!
	Memory::WriteInt(dwUpdateMouseLimitVPos + 1, m_nGameHeight);//mov ecx,600
	Memory::WriteInt(dwUpdateMouseLimitHPos + 1, m_nGameWidth);	//mov ecx,800 ; CInputSystem::UpdateMouse
	Memory::WriteInt(dwCursorPosLimitVPos + 1, m_nGameHeight);//mov eax,600
	Memory::WriteInt(dwCursorPosLimitHPos + 1, m_nGameWidth);	//mov eax,800 ; CInputSystem::SetCursorPos
	Memory::WriteInt(dwViewPortHeight + 3, m_nGameHeight);//lea eax,[esi+eax-600]
	Memory::WriteInt(dwViewPortWidth + 3, m_nGameWidth);	//lea eax,[ecx+eax-800]

	Memory::WriteInt(dwToolTipLimitVPos + 1, m_nGameHeight - 1); //mov eax,599 ; CUIToolTip::MakeLayer
	Memory::WriteInt(dwToolTipLimitHPos + 1, m_nGameWidth - 1); //mov eax,799 ; CUIToolTip::MakeLayer

	Memory::WriteInt(dwTempStatToolTipDraw + 3, -m_nGameWidth + 6); //lea eax,[eax+ecx-797] ; CTemporaryStatView::ShowToolTip
	Memory::WriteByte(0x007B9CB9 + 2, 26);   // 3 + 23                 buff tip y-pos range
	Memory::WriteByte(0x007B9CC2 + 2, 58);   // 35+23
	Memory::WriteInt(dwTempStatToolTipFind + 3, -m_nGameWidth + 6); //lea eax,[eax+ecx-797] ; CTemporaryStatView::FindIcon
	Memory::WriteByte(0x007B9EA7 + 2, 26);   // 3 + 23                  y-pos cancel range
	Memory::WriteByte(0x007B9EAC + 2, 58);   // 35 + 23
	Memory::WriteInt(dwTempStatIconVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon buff y-pos
	Memory::WriteInt(dwTempStatIconHpos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon buff x-pos
	Memory::WriteInt(dwTempStatCoolTimeVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon cooltime y-pos
	Memory::WriteInt(dwTempStatCoolTimeHPos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon cooltime x-pos

	int slotXPos = m_nGameWidth - 540;
	if (m_nGameWidth < 1366) {
		slotXPos = m_nGameWidth > 1024 ? 815 : 805;
	}
	Memory::WriteInt(dwQuickSlotInitVPos + 1, m_nGameHeight + 1);//add eax,533
	Memory::WriteInt(dwQuickSlotInitHPos + 1, slotXPos); //push 647 //hd800
	Memory::WriteInt(dwQuickSlotVPos + 2, m_nGameHeight + 1);//add esi,533
	Memory::WriteInt(dwQuickSlotHPos + 1, slotXPos); //push 647 //hd800
	Memory::WriteInt(dwQuickSlotCWndVPos + 2, -500); //lea edi,[eax-427]6
	Memory::WriteInt(dwQuickSlotCWndHPos + 2, -slotXPos); //lea ebx,[eax-647]
	Memory::WriteInt(0x008D6547 + 1, 540); //快捷面板宽度
	//4个快捷按钮位置
	Memory::WriteInt(0x008E4443 + 1, 506);  //装备按鈕高度
	Memory::WriteInt(0x008E4448 + 1, slotXPos + 7);  //装备按鈕寬度
	Memory::WriteInt(0x008E53F6 + 1, 506);  //装备闪烁高度
	Memory::WriteInt(0x008E53FB + 1, slotXPos + 7);  //装备闪烁寬度

	Memory::WriteInt(0x008E44C0 + 1, 506);  //背包按鈕高度
	Memory::WriteInt(0x008E44C5 + 1, slotXPos + 41);  //背包按鈕寬度
	Memory::WriteInt(0x008E5499 + 1, 506);  //背包闪烁高度
	Memory::WriteInt(0x008E549E + 1, slotXPos + 41);  //背包闪烁寬度

	Memory::WriteInt(0x008E453D + 1, 540);  //能力值按鈕高度
	Memory::WriteInt(0x008E4542 + 1, slotXPos + 7);  //能力值按鈕寬度
	Memory::WriteInt(0x008E5353 + 1, 540);  //能力值闪烁图标高度
	Memory::WriteInt(0x008E5358 + 1, slotXPos + 7);  //能力值闪烁图标宽度

	Memory::WriteInt(0x008E45BA + 1, 540);  //技能按鈕高度
	Memory::WriteInt(0x008E45BF + 1, slotXPos + 41);  //技能按鈕寬度
	Memory::WriteInt(0x008E5152 + 1, 540);  //技能按鈕高度
	Memory::WriteInt(0x008E5157 + 1, slotXPos + 41);  //技能按鈕寬度

	//Memory::WriteInt(dwByteAvatarMegaHPos + 1, m_nGameHeight + 100); //push 800 ; CAvatarMegaphone::ByeAvatarMegaphone ; IWzVector2D::RelMove ##BAK
	Memory::WriteInt(dwByteAvatarMegaHPos + 1, m_nGameWidth); //push 800 ; CAvatarMegaphone::ByeAvatarMegaphone ; IWzVector2D::RelMove
	Memory::WriteInt(dwAvatarMegaWidth + 1, m_nGameWidth); //push 800 ; CAvatarMegaphone ; CreateWnd

	Memory::WriteInt(0x00436E61 + 1, m_nGameHeight);    //->079 00436E61 600
	Memory::WriteInt(0x00436E67 + 1, m_nGameWidth);    // CreateWnd    //->079 00436E67 800
	Memory::WriteInt(0x00575D78 + 1, m_nGameHeight);                          //->079 00575D78 600
	Memory::WriteInt(0x00575D7D + 1, m_nGameWidth);    // RelMove?   //-> 079  00575D7D 800
	Memory::WriteInt(0x004E3250 + 1, m_nGameWidth);    // CreateWnd //-> 079 004E3250 || 004D875F 800
	Memory::WriteInt(0x004E33B5 + 2, m_nGameHeight);                          //->079 004E33B5 600
	Memory::WriteInt(0x004D88AF + 1, m_nGameWidth);    // CreateWnd //->079 004D88AF 800        
	Memory::WriteInt(0x004D88C4 + 1, m_nGameHeight);                         //-> 079 004D88C4 
	Memory::WriteInt(0x004E33A0 + 1, m_nGameWidth);    // CreateWnd //->079  004E33A0
	Memory::WriteInt(0x0086D3BC + 2, m_nGameWidth);                          //->079 0086D3BC 800
	Memory::WriteInt(0x0086D3C4 + 1, m_nGameWidth - 80);                      // CreateDlg//->079 0086D3C4  (TMS 700 CMS 704)
	Memory::WriteInt(0x008F224E + 1, m_nGameHeight);                        //-> 079 008F224E 800
	Memory::WriteInt(0x008F226A + 1, m_nGameWidth);    // RelMove? //->079 008F226A 600
	Memory::WriteInt(0x009A3691 + 1, m_nGameHeight);                      //->079 009A3691
	Memory::WriteInt(0x009A36A6 + 2, m_nGameWidth);                        //->079 009A36A6 
	Memory::WriteInt(0x009A36AE + 1, m_nGameWidth - 100);                     // CreateDlg //->079 009A36AE 700
	Memory::WriteInt(0x009AFFCD + 1, m_nGameHeight);                        //->079 009AFFCD 600
	Memory::WriteInt(0x009AFFC0 + 1, m_nGameWidth);    // CreateDlg //->079 009AFFC0 800
	Memory::WriteInt(0x0045B0C0 + 1, m_nGameHeight - 25);                //->079 0045B0C0 575
	Memory::WriteInt(0x0045B1A6 + 1, m_nGameWidth);    // RelMove? //->079 0045B1A6 900
	//Memory::WriteInt(0x004E7AF7 + 1, m_nGameWidth);                        //->079 004E7AF7 800   会导致商城选项卡点击失效


	Memory::WriteInt(0x00575D78 + 1, m_nGameHeight);                     //->079 00575D78 600
	Memory::WriteInt(0x00575D7D + 1, m_nGameWidth);                     //->079 00575D7D 800
	Memory::WriteInt(0x00575DF4 + 1, m_nGameWidth);    // RelMove? //->079 00575DF4 600
	Memory::WriteInt(0x007F7C0E + 1, m_nGameWidth);    // CreateWnd//->079 007F7C0E 800
	Memory::WriteInt(0x007F7C09 + 1, m_nGameHeight);                        //->079 007F7C09 600
	Memory::WriteInt(0x007F7C0E + 1, m_nGameWidth);    // CWnd::GetCanvas //->079 007F7C0E
	Memory::WriteInt(0x008BB421 + 1, m_nGameHeight);           //->079 008BB421
	Memory::WriteInt(0x008BB426 + 1, m_nGameWidth);    // CreateWnd           //->079 008BB426
	Memory::WriteInt(0x00A00FA0 + 1, m_nGameHeight);          //->079 00A00FA0
	Memory::WriteInt(0x00A00FA5 + 1, m_nGameWidth);    // StringPool#1162 (MapleStoryClass) //->079 00A00FA5
	Memory::WriteInt(0x005E0E32 + 1, m_nGameHeight);               //->079 005E0E32                     
	Memory::WriteInt(0x005E0E42 + 1, m_nGameWidth);    // RelMove?     //->079 005E0E42
	Memory::WriteInt(0x005E1C80 + 1, m_nGameHeight);                     //->079 005E1C80
	Memory::WriteInt(0x005E1C90 + 1, m_nGameWidth);    // RelMove?                     //->079 005E1C90
	Memory::WriteInt(0x005DFE68 + 1, m_nGameHeight);                    //->079 005DFE68
	Memory::WriteInt(0x005DFE78 + 1, m_nGameWidth);    // RelMove?                   //->079 005DFE78
	Memory::WriteInt(0x005E0E32 + 1, m_nGameHeight);                  //->079 005E0E32
	Memory::WriteInt(0x005E0E42 + 1, m_nGameWidth);    // RelMove?                  //->079 005E0E42
	Memory::WriteInt(0x005E1C80 + 1, m_nGameHeight);                //->079 005E1C80
	Memory::WriteInt(0x005E1C90 + 1, m_nGameWidth);    // RelMove?                  //->079 005E1C90
	Memory::WriteInt(0x005F5290 + 1, m_nGameHeight);                 //->079 005F5290
	Memory::WriteInt(0x005F52A0 + 1, m_nGameWidth);    // RelMove?                   //->079 005F52A0
	Memory::WriteInt(0x005F676B + 1, m_nGameHeight);                  //->079 005F676B
	Memory::WriteInt(0x005F677B + 1, m_nGameWidth);    // RelMove?                     //->079 005F677B
	Memory::WriteInt(0x007D69DF + 1, m_nGameHeight);                   //->079 007D69DF

	Memory::WriteInt(0x007D69ED + 1, m_nGameWidth);    // IWzVector2D::RelMove //->079 007D69ED 800
	Memory::WriteInt(0x008B23AC + 1, m_nGameHeight);                    //->079 008B23AC 600
	Memory::WriteInt(0x008B23BA + 1, m_nGameWidth);    // IWzVector2D::RelMove //->079 008B23BA 800
	Memory::WriteInt(0x0065ACF4 + 1, m_nGameHeight);                  //-> 079  0065ACF4 600 
	Memory::WriteInt(0x0065B4CB + 1, m_nGameWidth);    // IWzGr2DLayer::Getcanvas//->079 0065B4CB 800
	Memory::WriteInt(0x0065B4C6 + 1, m_nGameHeight);                        //->079 0065B4C6 600
	Memory::WriteInt(0x0065ACF9 + 1, m_nGameWidth);    // IWzGr2DLayer::Getcanvas//->079 0065ACF9  800
	Memory::WriteInt(0x0080AB3D + 1, m_nGameHeight);                       //->079 0080AB3D 600
	Memory::WriteInt(0x0080AB51 + 1, m_nGameWidth);    // CWnd::CreateWnd        //->079 0080AB51 800
	Memory::WriteInt(0x0065A64D + 1, m_nGameHeight);                    //->079 0065A64D || 0065A8E3 || 0065B030 600
	Memory::WriteInt(0x0065A652 + 1, m_nGameWidth);    // (UI/Logo/Wizet)          //->079 0065A652 || 0065B035 || 0065A8E8 800
	Memory::WriteInt(0x0065B4C6 + 1, m_nGameHeight);                       //->079 0065B4C6
	Memory::WriteInt(0x0065B4CB + 1, m_nGameWidth);    // Rectangle                         //->079 0065B4CB
	Memory::WriteInt(0x0066CB0A + 1, m_nGameHeight);                        //->079 0066CB0A
	Memory::WriteInt(0x0066CAF8 + 1, m_nGameWidth);                        //->079 0066CAF8
	Memory::WriteInt(0x0066CC90 + 1, m_nGameHeight);                        //->079 0066CC90
	Memory::WriteInt(0x0066CC7E + 1, m_nGameWidth);                        //->079 0066CC7E
	Memory::WriteInt(0x0066CC18 + 1, m_nGameHeight);                         //->079 0066CC18
	Memory::WriteInt(0x0066CC90 + 1, m_nGameHeight);                        //->079 0066CC90
	Memory::WriteInt(0x0066CC1D + 1, m_nGameHeight);                        //->079 0066CC1D
	Memory::WriteInt(0x0066CC4B + 1, m_nGameHeight);                        //->079 0066CC4B
	Memory::WriteInt(0x0066CC06 + 1, m_nGameWidth);                          //->079 0066CC06
	Memory::WriteInt(0x0066CC7E + 1, m_nGameWidth);                          //->079 0066CC7E
	Memory::WriteInt(0x0066CC39 + 1, m_nGameWidth);                          //->079 0066CC39
	Memory::WriteInt(0x0066CA3E + 1, floor(m_nGameWidth / 2));             //->079 0066CA3E
	Memory::WriteInt(0x0066CA43 + 1, floor(m_nGameHeight / 2));            //->079 0066CA43
	Memory::WriteInt(0x0066CC26 + 1, floor(m_nGameWidth / 2));                // bunch of modulus stuff    //->079 0066CC26
	Memory::WriteInt(0x0066E0C6 + 3, m_nGameHeight);                          //->079 0066E0C6
	Memory::WriteInt(0x0066E0BF + 3, m_nGameWidth);    // idk               //->079 0066E0BF
	Memory::WriteInt(0x0066E1E5 + 3, m_nGameHeight);                             //->079 0066E1E5
	Memory::WriteInt(0x0066E1DB + 3, m_nGameWidth);    // CAnimationDisplayer::SetCenterOrigin          //->079 0066E1DB
	Memory::WriteInt(0x0046B007 + 1, m_nGameHeight);                            //->079 0046B007
	Memory::WriteInt(0x0046B019 + 1, m_nGameWidth);    // IWzVector2D::RelMove         //->079 0046B019
	Memory::WriteInt(0x009A4FDB + 1, m_nGameHeight);                            //->079 009A4FDB 
	Memory::WriteInt(0x009A4FF0 + 2, m_nGameWidth);                                //->079 009A4FF0
	Memory::WriteInt(0x009A4FF8 + 1, m_nGameWidth - 100);                     // CreateDlg                             //->079 009A4FF8
	Memory::WriteInt(0x0066E675 + 1, floor(m_nGameHeight / 2));               // VRRight        //->079 0066E675
	Memory::WriteInt(0x0066E73C + 1, floor(m_nGameHeight / 2));               //->079 0066E73C
	Memory::WriteInt(0x0066E60E + 1, floor(m_nGameWidth / 2));                // VRTop                              //->079 0066E60E
	Memory::WriteInt(0x006BE6EA + 1, floor(m_nGameWidth / 2));                // RelMove?                         //->079 006BE6EA
	Memory::WriteInt(0x005CA78D + 6, floor(m_nGameHeight / 2));             //->079 005CA78D
	Memory::WriteInt(0x005CA787 + 2, floor(m_nGameWidth / 2));                // CInputSystem::LoadCursorState               //->079 005CA787
	Memory::WriteInt(0x0081C817 + 1, m_nGameHeight);                           //->079 0081C817
	Memory::WriteInt(0x0081C804 + 1, m_nGameWidth);    // CUIEventAlarm::CreateEventAlarm              //->079 0081C804
	Memory::WriteInt(0x008D4C75 + 1, m_nGameHeight - 22);                    //->079 008D4C75
	Memory::WriteInt(0x008D4C7A + 1, m_nGameWidth);                            //->079 008D4C7A


	Memory::WriteInt(0x00436F9C + 1, floor(-m_nGameHeight / 2));            //->079 00436F9C
	Memory::WriteInt(0x00436F9C + 1, floor(-m_nGameWidth / 2));               // RelMove?                         //->079 00436F9C
	Memory::WriteInt(0x0057609F + 1, floor(-m_nGameHeight / 2));            //->079 0057609F
	Memory::WriteInt(0x005760A5 + 1, floor(-m_nGameWidth / 2));               // RelMove?                          //->079 005760A5
	Memory::WriteInt(0x00436F97 + 1, floor(-m_nGameHeight / 2));            //->079 00436F97
	Memory::WriteInt(0x00436F9C + 1, floor(-m_nGameWidth / 2));               // RelMove?                          //->079 00436F9C
	Memory::WriteInt(0x006BF23E + 1, m_nGameWidth);                            //->079 006BF23E
	Memory::WriteInt(0x007F8207 + 1, m_nGameWidth);                            //->079 007F8207
	Memory::WriteInt(0x008DCDED + 1, m_nGameHeight - 22);                    //->079 008DCDED
	Memory::WriteInt(0x008DCDF2 + 1, m_nGameWidth);                             //->079 008DCDF2
	Memory::WriteInt(0x0093BEAD + 1, floor(m_nGameHeight / 2));             //->079 0093BEAD     
	Memory::WriteInt(0x0093BEA8 + 1, m_nGameWidth);    // RelMove? (Skills)                  //->079 0093BEA8
	Memory::WriteInt(0x009E9D8C + 1, m_nGameWidth);                           //->079 009E9D8C
	Memory::WriteInt(0x009E9F02 + 1, m_nGameHeight);                          // IWzVector2D::RelMove         //->079 009E9F02
	Memory::WriteInt(0x009FF84F + 1, floor(m_nGameHeight / 2));               // MapleStoryClass               //->079 009FF84F
	Memory::WriteInt(0x006E7F58 + 1, m_nGameHeight);                          // 006E8BFF 006E9379 006EA459    /->079 006E7F58 || 006E72BD || 006E8849
	Memory::WriteInt(0x0075930E + 1, m_nGameHeight);                            //->079 0075930E
	Memory::WriteInt(0x007591B6 + 1, m_nGameHeight);                            //->079 007591B6
	Memory::WriteInt(0x00758D04 + 1, m_nGameHeight);                           //->079 00758D04
	Memory::WriteInt(0x00758C19 + 1, m_nGameHeight);                           //->079 00758C19
	Memory::WriteInt(0x0066E860 + 1, m_nGameHeight);                          // CSoundMan::PlayBGM         //->079 0066E860
	Memory::WriteInt(0x00634BB1 + 1, m_nGameHeight);                          //->079 00634BB1
	Memory::WriteInt(0x00634BBB + 1, floor(-m_nGameHeight / 2));                                 //->079 00634BBB
	Memory::WriteInt(0x0061ACCE + 1, m_nGameHeight);                           //->079 0061ACCE
	Memory::WriteInt(0x005D4261 + 1, m_nGameHeight);                          // CSoundMan::PlayBGM
	Memory::WriteInt(0x008D7458 + 1, m_nGameHeight - 33);                     // IWzVector2D::RelMove
	Memory::WriteInt(0x008E36A8 + 1, m_nGameHeight - 20);
	Memory::WriteInt(0x008E3944 + 1, m_nGameHeight - 20);
	Memory::WriteInt(0x008D7739 + 1, m_nGameHeight - 19);
	Memory::WriteInt(0x008D797F + 1, m_nGameHeight - 19);
	Memory::WriteInt(0x008DD6F6 + 1, m_nGameHeight - 19);
	Memory::WriteInt(0x008DDE76 + 1, m_nGameHeight - 19);
	Memory::WriteInt(0x008DE5C1 + 1, m_nGameHeight - 19);
	Memory::WriteInt(0x008DEC14 + 1, m_nGameHeight - 19);	//push 581 临时经验条
	Memory::WriteInt(0x008D6D3B + 1, m_nGameHeight - 22);

	Memory::WriteInt(0x008D6D40 + 1, m_nGameWidth);
	Memory::WriteInt(0x008D6FE3 + 1, m_nGameHeight - 22);
	Memory::WriteInt(0x008D6FE8 + 1, m_nGameWidth);    // CUIStatusBar
	Memory::WriteInt(0x0065B4C6 + 1, m_nGameHeight);
	Memory::WriteInt(0x0065B4CB + 1, m_nGameWidth);    // (UI/Logo/Nexon)
	Memory::WriteInt(0x004FD494 + 1, m_nGameWidth);
	Memory::WriteInt(0x004FD483 + 1, m_nGameHeight);                          // CreateWnd
	Memory::WriteInt(0x004FD3E3 + 1, m_nGameWidth);
	Memory::WriteInt(0x004FD3CA + 1, m_nGameHeight);
	Memory::WriteInt(0x009FFF02, m_nGameHeight);
	Memory::WriteInt(0x009FFF07, m_nGameWidth);
	Memory::WriteInt(0x00BD1788, floor(m_nGameWidth / 2));
	Memory::WriteInt(0x00BD35E4, floor(m_nGameHeight / 2));
	Memory::WriteInt(0x00BD35E0, floor(m_nGameWidth / 2));
	Memory::WriteInt(0x0066CC56 + 2, floor(-m_nGameWidth / 2));
	Memory::WriteInt(0x0066D6AD + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0066D6B5 + 1, floor(-m_nGameWidth / 2));
	Memory::WriteInt(0x006BF359 + 1, floor(-m_nGameWidth / 2));
	Memory::WriteInt(0x009EC61A + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x009EC620 + 1, floor(-m_nGameWidth / 2));
	Memory::WriteInt(0x0093B675 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0095DBA3 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0098EE27 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0098F84C + 2, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x00A4EAC9 + 2, floor(-m_nGameHeight / 2));              // CWvsPhysicalSpace2D::Load          //->079 00A4EAC9 || 00A55A79 -300
	Memory::WriteInt(0x00669275 + 2, floor(-m_nGameWidth / 2));
	Memory::WriteInt(0x009CFD87 + 3, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x009CFD95 + 3, floor(m_nGameHeight / 2));

	//Memory::WriteInt(0x009F7078 + 1, m_nGameHeight);//??related to application dimensions	//(ragezone release merge)//thanks mr mr of ragezone for these addresses
	//Memory::WriteInt(0x009F707D + 1, m_nGameWidth);//??related to application dimensions

	//Memory::WriteInt(0x0058C8A6 + 1, m_nGameWidth);//??

	//Memory::WriteInt(0x004EDABF + 1, m_nGameHeight);//??

	//Memory::WriteInt(0x00991854 + 1, m_nGameHeight);//??unknown cwnd function
	//Memory::WriteInt(0x0099185F + 1, (m_nGameWidth / 2) - 134);//??unknown cwnd function
	//Memory::WriteInt(0x00991867 + 1, (m_nGameWidth / 2) - 133);//??unknown cwnd function
	//Memory::WriteInt(0x00992BA7 + 1, (unsigned int)floor(m_nGameWidth / 2));//??unknown cwnd function, possibly related to cutildlg
	//Memory::WriteInt(0x00992BAC + 1, (unsigned int)floor(m_nGameHeight / 2));//??unknown cwnd function, possibly related to cutildlg

	Memory::WriteInt(0x007F8357 + 2, m_nGameWidth);//related to displaying server message at top of screen
	Memory::WriteInt(0x007F7F1A + 2, m_nGameWidth);//related to displaying server message at top of screen

	Memory::WriteInt(0x005462B2 + 1, (m_nGameWidth / 2) - 129);//related to boss bar
	//Memory::WriteInt(0x005364AA + 2, (m_nGameWidth / 2) - 128);//??related to boss bar
	Memory::WriteInt(0x00A2E4F9 + 1, (m_nGameWidth / 2) - 129); //??
	Memory::WriteByte(0x005434BA, 0xB8);	//boss bar extend to window
	Memory::WriteInt(0x005434BA + 1, m_nGameWidth - 2);	//boss bar	extend to window
	Memory::WriteByte(0x00543D27, 0xB9);	//boss bar	extend to window
	Memory::WriteInt(0x00543D27 + 1, m_nGameWidth - 9);	//boss bar	extend to window

	//Memory::WriteInt(0x00592A08 + 1, (m_nGameWidth / 2) - 125);//??likely related to mouse pos

	//Memory::WriteInt(0x00621226 + 1, (m_nGameWidth / 2) - 216);//??possibly related to logo
	//Memory::WriteByte(0x0062121E + 1, 0x01);//??possibly related to logo

	//Memory::WriteInt(0x008C069F + 1, (m_nGameHeight / 2) - 14);//??related to status bar
	//Memory::WriteInt(0x008C06A4 + 1, (m_nGameWidth / 2) - 158);//???related to status bar

	//Memory::WriteInt(0x00A24D0B + 1, (m_nGameWidth / 2) - 129);//??

	//Memory::WriteInt(0x00BE273C, 128);//??
	//Memory::WriteByte(0x00A5FC2B, 0x05);//??
	////Memory::WriteByte(0x008D1790 + 2, 0x01); //related to quickslots area presence		 originally 1U but changed because unsigned int crashes it after char select
	//Memory::WriteByte(0x00592A06 + 1, 0x01);//???likely related to mouse pos

	Memory::WriteInt(0x007518B2 + 1, m_nGameWidth);//??related to in-game taking screenshot functionality
	Memory::WriteInt(0x007518B7 + 1, m_nGameHeight);//??related to in-game taking screenshot functionality
	Memory::WriteInt(0x00751828 + 1, 3 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality
	Memory::WriteInt(0x00751841 + 1, m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality
	Memory::WriteInt(0x007517A4 + 1, 4 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality

	//Memory::WriteInt(0x008A8FA9 + 1, (m_nGameWidth / 2) - 143);//??related to exp gain/item pick up msg

	Memory::WriteInt(0x0062A7DE + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	Memory::WriteInt(0x0062A922 + 1, (unsigned int)floor(-m_nGameHeight / 2));	//push -300 ;
	Memory::WriteInt(0x00628EFB + 1, (unsigned int)floor(m_nGameWidth / 2));//??related to login game frame

	//Memory::WriteInt(0x0060411C + 1, m_nGameHeight);//push 600
	//Memory::WriteInt(0x00604126 + 1, floor(-m_nGameWidth / 2));	//push -300 //moves characters side to side on char select //unnecessary atm
	Memory::WriteInt(0x0063C5B4 + 1, (m_nGameHeight / 2) - 201);//??possibly related to login utildlg
	Memory::WriteInt(0x0063C5BD + 1, (m_nGameHeight / 2) - 181);//??possibly related to login utildlg
	Memory::WriteInt(0x0063C5C5 + 1, (m_nGameWidth / 2) - 201);//??possibly related to login utildlg
	Memory::WriteInt(0x0063C5CE + 1, (m_nGameWidth / 2) - 181);//??possibly related to login utildlg
	//Memory::WriteInt(0x00613093 + 1, (m_nGameHeight / 2) - 200);//??likely related to login pop-up msg
	//Memory::WriteInt(0x00613099 + 1, (m_nGameWidth / 2) - 45);//??likely related to login pop-up msg
	//Memory::WriteInt(0x0061DAFF + 1, (m_nGameHeight / 2) - 150);//??likely related to login pop-up msg
	//Memory::WriteInt(0x0061DB08 + 1, (m_nGameHeight / 2) - 130);//??likely related to login pop-up msg
	//Memory::WriteInt(0x0061DB10 + 1, (m_nGameWidth / 2) - 201);//??likely related to login pop-up msg
	//Memory::WriteInt(0x0061DB19 + 1, (m_nGameWidth / 2) - 181);//??likely related to login pop-up msg

	if (WindowedMode) {
		unsigned char forced_window[] = { 0xB8, 0x00, 0x00, 0x00, 0x00 }; //force window mode	//thanks stelmo for showing me how to do this
		Memory::WriteByteArray(0x00A00EF2, forced_window, sizeof(forced_window));//force window mode
	}
	if (RemoveLogos) {
		Memory::FillBytes(0x0065A398, 0x90, 20);	//no Logo @launch
	}

	int msgAmntOffset, msgAmnt; msgAmnt = MsgAmount; msgAmntOffset = msgAmnt * 14;

	Memory::WriteInt(0x008AC830 + 1, m_nGameHeight - 6 - msgAmntOffset);//inventory/exp gain y axis //####hd100 //90
	Memory::WriteInt(0x008AC8EE + 1, m_nGameWidth - 405);//inventory/exp gain x axis //310 //####hd415 //405
	Memory::WriteInt(0x008AC98D + 1, m_nGameHeight - 6 - msgAmntOffset); //related to quickslots area presence
	Memory::WriteInt(0x008ACBFA + 1, m_nGameWidth - 405);

	Memory::WriteInt(0x008AC12A + 1, 400);//length of pick up and exp gain message canvas //found with help from Davi
	Memory::WriteInt(0x008AC4BD + 1, 400);//address to move the message in the canvas adjusted above to the center of the new canvas  //thanks chris

	Memory::WriteInt(0x008AC0D9 + 3, msgAmnt);//moregainmsgs part 1
	MoreGainMsgsOffset = msgAmnt;	//param for ccmoregainmssgs
	Memory::CodeCave(ccMoreGainMsgs, dwMoreGainMsgs, MoreGainMsgsNOPs); //moregainmsgs part 2
	MoreGainMsgsFadeOffset = 15000;	//param for ccmoregainmssgsFade
	Memory::CodeCave(ccMoreGainMsgsFade, dwMoreGainMsgsFade, MoreGainMsgsFadeNOPs); //moregainmsgsFade
	MoreGainMsgsFade1Offset = 255 * 4 / 3;	//param for ccmoregainmssgsFade
	Memory::CodeCave(ccMoreGainMsgsFade1, dwMoreGainMsgsFade1, MoreGainMsgsFade1NOPs); //moregainmsgsFade1

	//Memory::WriteInt(0x0045B337 + 1, m_nGameWidth);//related to smega display  //likely screen area where pop up starts for smega
	//Memory::WriteInt(0x0045B417 + 1, m_nGameWidth - 225);//smega with avatar x axis for duration on screen

	//Memory::WriteInt(0x007C2531 + 1, m_nGameHeight - 80);//??

	Memory::WriteInt(0x0066D6A4 + 2, m_nGameWidth);
	Memory::WriteInt(0x0066D69D + 2, m_nGameHeight);

	Memory::WriteInt(0x005DDAAF + 1, m_nGameWidth);
	Memory::WriteInt(0x005DDA9F + 1, m_nGameHeight);

	Memory::WriteInt(0x0061FA6F + 1, m_nGameWidth);
	Memory::WriteInt(0x0061FA65 + 1, m_nGameHeight);

	Memory::WriteInt(0x007EC157 + 1, m_nGameWidth);
	Memory::WriteInt(0x007EC146 + 1, m_nGameHeight);

	Memory::WriteInt(0x00804E8F + 1, m_nGameWidth);
	Memory::WriteInt(0x00804E7E + 1, m_nGameHeight);

	Memory::WriteInt(0x007F7AD5 + 1, m_nGameWidth);

	Memory::WriteInt(0x0065A8E8 + 1, m_nGameWidth);   //未知
	Memory::WriteInt(0x0065A8E3 + 1, m_nGameHeight);

	Memory::WriteInt(0x005B7123 + 1, m_nGameWidth);  //顶部喇叭位置
	//喇叭
	Memory::WriteInt(0x00459F1B + 1, m_nGameWidth);				 //   所有动画位置参数都是 左上角  右上角 宽 高
	Memory::WriteInt(0x0045AB28 + 1, m_nGameWidth + 100);  //飘入喇叭起始位置
	Memory::WriteInt(0x0045AC0A + 1, m_nGameWidth - 225);  //飘入喇叭终止位置
	Memory::WriteInt(0x0099EBBC + 1, m_nGameWidth / 2 - 133); //蓝色提示框
	Memory::WriteInt(0x0099EBA9 + 1, m_nGameHeight);
	Memory::WriteInt(0x005BBAE8 + 1, m_nGameWidth); //顶部通知
	Memory::WriteInt(0x005BBAE3 + 1, m_nGameHeight);
	Memory::WriteInt(0x005EE9E7 + 1, m_nGameWidth / 2); //地图指示
	Memory::WriteInt(0x005449E2 + 1, 230);

	Memory::WriteInt(0x008581D3 + 1, m_nGameHeight - 198); //system menu pop up
	Memory::WriteInt(0x008589E8 + 1, m_nGameHeight - 281); //shortcuts pop up	//0x84A5BD -  System Options "X" Position. if needed

	//各种气泡
	Memory::WriteInt(0x0052D694 + 1, m_nGameHeight - 92 - 10);// ??various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052D886 + 1, m_nGameHeight - 92 - 10); // ??various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052DA9F + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052DD77 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052DFB3 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up //quest complete y axis
	Memory::WriteInt(0x0052E1A9 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052E39B + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052E5CF + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052E7C3 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052E9C1 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052EDF9 + 1, m_nGameHeight - 92 - 10);// various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052F0E1 + 1, m_nGameHeight - 102 - 10);//?? various requests like party, guild, friend, family, invites that pop up
	Memory::WriteInt(0x0052EBAA + 1, m_nGameHeight - 102 - 10);//party quest available pop-up y axis

	Memory::WriteInt(0x0052D6A8 + 1, 582);
	Memory::WriteInt(0x0052D89A + 1, 582);//various requests like party, guild, friend, family, invites that pop up //Party Invite
	Memory::WriteInt(0x0052DAB3 + 1, 582);//various requests like party, guild, friend, family, invites that pop up //friend request
	Memory::WriteInt(0x0052DD8B + 1, 582);//various requests like party, guild, friend, family, invites that pop up	// Guild Invite
	Memory::WriteInt(0x0052DFC7 + 1, 582);//various requests like party, guild, friend, family, invites that pop up//??
	Memory::WriteInt(0x0052DAB3 + 1, 582);//various requests like party, guild, friend, family, invites that pop up/??
	Memory::WriteInt(0x0052E1BD + 1, 582);//various requests like party, guild, friend, family, invites that pop up/??
	Memory::WriteInt(0x0052E3AF + 1, 582);//various requests like party, guild, friend, family, invites that pop up// ??
	Memory::WriteInt(0x0052E5E3 + 1, 582);//various requests like party, guild, friend, family, invites that pop up// ??
	Memory::WriteInt(0x0052E7E3 + 1, 582);//various requests like party, guild, friend, family, invites that pop up//??
	Memory::WriteInt(0x0052E9D5 + 1, 582);
	Memory::WriteInt(0x0052EBBE + 1, 582);
	Memory::WriteInt(0x0052EE0D + 1, 582);
	Memory::WriteInt(0x0052F0F5 + 1, 582);


	myHeight = (Client::m_nGameHeight - 600) / 2;//cash shop fix for frame area	//recalc offsets
	myWidth = (Client::m_nGameWidth - 800) / 2;//cash shop fix for frame area		//recalc offsets

	// 现金商城居中
	nHeightOfsetted1 = 316; nWidthOfsetted1 = 256; nTopOfsetted1 = 0 + myHeight; nLeftOfsetted1 = 0 + myWidth; //parameters for fix1
	Memory::CodeCave(CashShopFix1, dwCashFix1, dwCashFix1NOPs);
	nHeightOfsetted2 = 104; nWidthOfsetted2 = 256; nTopOfsetted2 = 318 + myHeight; nLeftOfsetted2 = -1 + myWidth; //parameters for fix2
	Memory::CodeCave(CashShopFix2, dwCashFix2, dwCashFix2NOPs);
	nHeightOfsetted3 = 163; nWidthOfsetted3 = 246; nTopOfsetted3 = 426 + myHeight; nLeftOfsetted3 = 0 + myWidth; //parameters for fix3
	Memory::CodeCave(CashShopFix3, dwCashFix3, dwCashFix3NOPs);
	nHeightOfsetted4 = 78; nWidthOfsetted4 = 508; nTopOfsetted4 = 17 + myHeight; nLeftOfsetted4 = 272 + myWidth; //parameters for fix4   top
	Memory::CodeCave(CashShopFix4, dwCashFix4, dwCashFix4NOPs);
	nHeightOfsetted5 = 430; nWidthOfsetted5 = 412; nTopOfsetted5 = 95 + myHeight; nLeftOfsetted5 = 275 + myWidth; //parameters for fix5
	Memory::CodeCave(CashShopFix5, dwCashFix5, dwCashFix5NOPs);	//main part of shop, item listings	//thanks angel for stuff that helped
	Memory::CodeCave(CashShopFix9, dwCashFix9, dwCashFix9NOPs);	//main part of shop 2
	nHeightOfsetted6 = 358; nWidthOfsetted6 = 90; nTopOfsetted6 = 157 + myHeight; //parameters for fix6
	Memory::CodeCave(CashShopFix6, dwCashFix6, dwCashFix6NOPs);//code cave 6 //best sellers
	Memory::WriteInt(0x00468F7F + 1, myWidth + 690);//nleft, actual drawn part	//best sellers
	nHeightOfsetted7 = 56; nWidthOfsetted7 = 545; nTopOfsetted7 = 536 + myHeight; nLeftOfsetted7 = 254 + myWidth; //parameters for fix7   bottom exit
	Memory::CodeCave(CashShopFix7, dwCashFix7, dwCashFix7NOPs);
	nHeightOfsetted8 = 22; nWidthOfsetted8 = 89; nTopOfsetted8 = 97 + myHeight; nLeftOfsetted8 = 690 + myWidth; //parameters for fix8
	Memory::CodeCave(CashShopFix8, dwCashFix8, dwCashFix8NOPs);
	Memory::CodeCave(CashShopFixOnOff, dwCashFixOnOff, dwCashFixOnOffNOPs);	//fix for preview On/Off button not being accurate on entering cash shop //thanks windyboy

	nHeightOfsettedPrev = 165 + myHeight; nWidthOfsettedPrev = 212 + myWidth; nTopOfsettedPrev = 40 + myHeight; nLeftOfsettedPrev = 24 + myWidth; //parameters for fix cash preview
	Memory::CodeCave(CashShopFixPrev, dwCashFixPrev, dwCashFixPrevNOPs); //cash shop preview fix

	// 交易中心居中
	iHeightOfsetted1 = 200; iWidthOfsetted1 = 256; iTopOfsetted1 = 0 + myHeight; iLeftOfsetted1 = 0 + myWidth;
	Memory::CodeCave(ITCFix1, 0x005D40F9, 12);
	iHeightOfsetted2 = 110; iWidthOfsetted2 = 256; iTopOfsetted2 = 200 + myHeight; iLeftOfsetted2 = -1 + myWidth;
	Memory::CodeCave(ITCFix2, 0x005D4111, 13);
	iHeightOfsetted3 = 108; iWidthOfsetted3 = 256; iTopOfsetted3 = 310 + myHeight; iLeftOfsetted3 = 0 + myWidth;
	Memory::CodeCave(ITCFix3, 0x005D412D, 13);
	iHeightOfsetted4 = 180; iWidthOfsetted4 = 256; iTopOfsetted4 = 418 + myHeight; iLeftOfsetted4 = 0 + myWidth;
	Memory::CodeCave(ITCFix4, 0x005D4149, 16);
	iHeightOfsetted5 = 78; iWidthOfsetted5 = 509; iTopOfsetted5 = 17 + myHeight; iLeftOfsetted5 = 272 + myWidth;
	Memory::CodeCave(ITCFix5, 0x005D4167, 16);	//main part of shop, item listings	//thanks angel for stuff that helped
	iHeightOfsetted6 = 48; iWidthOfsetted6 = 509; iTopOfsetted6 = 98 + myHeight; iLeftOfsetted6 = 273 + myWidth;
	Memory::CodeCave(ITCFix6, 0x005D4186, 14);//code cave 6 //best sellers
	iHeightOfsetted7 = 365; iWidthOfsetted7 = 509; iTopOfsetted7 = 145 + myHeight; iLeftOfsetted7 = 273 + myWidth;
	Memory::CodeCave(ITCFix7, 0x005D41A3, 20);
	iHeightOfsetted8 = 56; iWidthOfsetted8 = 545; iTopOfsetted8 = 531 + myHeight; iLeftOfsetted8 = 255 + myWidth;
	Memory::CodeCave(ITCFix8, 0x005D41C6, 17);

	//Memory::WriteInt(0x0066E6DC + 2, (unsigned int)floor(m_nGameWidth / 2));	//mov ebc,400 ;  VRright		//camera movement	//crashes
	Memory::WriteInt(0x0066E73C + 1, (unsigned int)floor(m_nGameHeight / 2));	//add eax,300  ; VRbottom //camera movement //not working for most maps

	myAlwaysViewRestoreFixOffset = myHeight; //parameters for fix view restore all maps number ?????working????!!!
	Memory::CodeCave(AlwaysViewRestoreFix, dwAlwaysViewRestoreFix, dwAlwaysViewRestoreFixNOPs);

	if (CustomLoginFrame) {
		Memory::WriteInt(0x00629120 + 1, (unsigned int)floor(-m_nGameHeight / 2));//push -300				!!game login frame!! turn this on if you edit UI.wz and use a frame that matches your res
		Memory::WriteInt(0x0062912F + 1, (unsigned int)floor(-m_nGameWidth / 2));	//push -400 ; RelMove?				!!game login frame!! turn this on if you edit UI.wz and use a frame that matches your res
	}

	if (bigLoginFrame) {
		Memory::WriteInt(0x00628EFB + 1, m_nGameWidth - 145);	// 145?? mov eax,800 ; RelMove?	//game version number for login frames that hug the side of the screen //you will still need to offset ntop, and that may require a code cave if your height resolution is too big
	}
	else {
		nTopOfsettedVerFix = 10 + myHeight; nLeftOfsettedVerFix = 665 + myWidth; //parameters for fix version number
		Memory::CodeCave(VersionNumberFix, dwVersionNumberFix, dwVersionNumberFixNOPs);	//game version number fix //use this if you use no frame or default client frame
	}

	if (!bigLoginFrame) {
		nHeightOfsettedLoginBackCanvasFix = 122 + myHeight; nWidthOfsettedLoginBackCanvasFix = 85 + myWidth;//para for world select buttonsViewRec
		nTopOfsettedLoginBackCanvasFix = 452 + myHeight; nLeftOfsettedLoginBackCanvasFix = 76 + myWidth;
		Memory::CodeCave(ccLoginBackCanvasFix, dwLoginBackCanvasFix, LoginBackCanvasFixNOPs);	//world select buttons fix		//thank you teto for pointing out my error in finding the constructor

		//yOffsetOfLoginBackBtnFix = 300 + myHeight; xOffsetOfLoginBackBtnFix = 0 + myWidth;	//para for back button
		//Memory::CodeCave(ccLoginBackBtnFix, dwLoginBackBtnFix, LoginBackBtnFixNOPs); //back button on world select //unnecessary as buttons move with canvas

		nHeightOfsettedLoginViewRecFix = 122 + myHeight; nWidthOfsettedLoginViewRecFix = 85 + myWidth;//para for ViewRec fix
		nTopOfsettedLoginViewRecFix = 452 + myHeight; nLeftOfsettedLoginViewRecFix = 76 + myWidth;
		Memory::CodeCave(ccLoginViewRecFix, dwLoginViewRecFix, LoginViewRecFixNOPs);	//world ViewRec fix	

		a1x = 0 + myWidth; a2x = -149 + myWidth; a2y = 0 + myHeight; a3 = 25; a1y = -250; //a4 = 0;	//LoginDescriptor params
		Memory::WriteInt(0x0063ABC4 + 1, 300 + a1y); //speed 1	//temporary fix by increasing the speed of display until i get good enough at procedural programming 
		//and memory management and reverse engineering to use nexon's own functions to put a black layer with greater z value to cover the tabs being shown off screen at origin
		Memory::CodeCave(ccLoginDescriptorFix, dwLoginDescriptorFix, LoginDescriptorFixNOPs);	//world LoginDescriptor fix	
	}

	int customEngY = -62, customEngX = -22, dojangYoffset = 0;	//myHeight //-55-35 (myHeight*250/100)	-(myWidth*53/100) 140 -130
	yOffsetOfMuruengraidPlayer = 50 + dojangYoffset; xOffsetOfMuruengraidPlayer = 169 + myWidth; //params
	Memory::CodeCave(ccMuruengraidPlayer, dwMuruengraidPlayer, MuruengraidPlayerNOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidClock = 26 + dojangYoffset; xOffsetOfMuruengraidClock = 400 + myWidth; //params
	Memory::CodeCave(ccMuruengraidClock, dwMuruengraidClock, MuruengraidClockNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidMonster = 50 + dojangYoffset; xOffsetOfMuruengraidMonster = 631 + myWidth; //params
	Memory::CodeCave(ccMuruengraidMonster, dwMuruengraidMonster, MuruengraidMonsterNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidMonster1 = 32 + dojangYoffset; xOffsetOfMuruengraidMonster1 = 317 + myWidth; //params
	Memory::CodeCave(ccMuruengraidMonster1, dwMuruengraidMonster1, MuruengraidMonster1NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidMonster2 = 32 + dojangYoffset; xOffsetOfMuruengraidMonster2 = 482 + myWidth; //params
	Memory::CodeCave(ccMuruengraidMonster2, dwMuruengraidMonster2, MuruengraidMonster2NOPs);	//muruengraid scaling
	yOffsetOfMuruengraidEngBar = 86 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar = 17 + myWidth + customEngX; //params
	Memory::CodeCave(ccMuruengraidEngBar, dwMuruengraidEngBar, MuruengraidEngBarNOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidEngBar1 = 130 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar1 = 20 + myWidth + customEngX; //params
	Memory::CodeCave(ccMuruengraidEngBar1, dwMuruengraidEngBar1, MuruengraidEngBar1NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidEngBar2 = 80 + dojangYoffset + customEngY; xOffsetOfMuruengraidEngBar2 = 9 + myWidth + customEngX; //params
	Memory::CodeCave(ccMuruengraidEngBar2, dwMuruengraidEngBar2, MuruengraidEngBar2NOPs);	//muruengraid scaling	
	yOffsetOfMuruengraidClearRoundUI = 260 + myHeight; xOffsetOfMuruengraidClearRoundUI = 400 + myWidth; //params
	Memory::CodeCave(ccMuruengraidClearRoundUI, dwMuruengraidClearRoundUI, MuruengraidClearRoundUINOPs);	//muruengraid scaling
	//yOffsetOfMuruengraidTimerCanvas = 28 + dojangYoffset; xOffsetOfMuruengraidTimerCanvas = 112 + myWidth; //params
	//Memory::CodeCave(ccMuruengraidTimerCanvas, dwMuruengraidTimerCanvas, MuruengraidTimerCanvasNOPs);	//muruengraid scaling	
	//yOffsetOfMuruengraidTimerMinutes = 0 + dojangYoffset; xOffsetOfMuruengraidTimerMinutes = 0 + myWidth; //params	//not needed, bar moves all, kept for referrence or if change are needed
	//Memory::CodeCave(ccMuruengraidTimerMinutes, dwMuruengraidTimerMinutes, MuruengraidTimerMinutesNOPs);	//muruengraid scaling	
	//yOffsetOfMuruengraidTimerSeconds = 0 + dojangYoffset; xOffsetOfMuruengraidTimerSeconds = 68 + myWidth; //params
	//Memory::CodeCave(ccMuruengraidTimerSeconds, dwMuruengraidTimerSeconds, MuruengraidTimerSecondsNOPs);	//muruengraid scaling
	yOffsetOfMuruengraidTimerBar = 16 + dojangYoffset; xOffsetOfMuruengraidTimerBar = 345 + myWidth; //params
	Memory::CodeCave(ccMuruengraidTimerBar, dwMuruengraidTimerBar, MuruengraidTimerBarNOPs);	//muruengraid scaling
	xOffsetOfMuruengraidMonster1_2 = 318 + myWidth; //params	//finally fixed this bugger
	Memory::CodeCave(ccMuruengraidMonster1_2, dwMuruengraidMonster1_2, MuruengraidMonster1_2NOPs);

	//黑暗地图
	darkCircleX = m_nGameWidth / 2 - 163;
	darkCircleY = m_nGameHeight / 2 - 190;
	Memory::CodeCave(darkMap1cc, 0x00576456, 9);
	Memory::CodeCave(darkMap2cc, 0x005765EF, 12);
	Memory::CodeCave(darkMap3cc, 0x00576735, 13);
}

void Client::EnableNewIGCipher() {//??not called //no idea what cipher is
	const int nCipherHash = m_nIGCipherHash;
	Memory::WriteInt(dwIGCipherHash + 3, nCipherHash);
	Memory::WriteInt(dwIGCipherVirtual1 + 3, nCipherHash);
	Memory::WriteInt(dwIGCipherVirtual2 + 3, nCipherHash);
	Memory::WriteInt(dwIGCipherDecrypt + 3, nCipherHash);
	Memory::WriteInt(dwIGCipherDecryptStr + 3, nCipherHash);
}

void Client::UpdateLogin() {	//un-used //may still contain some useful addresses for custom login
	Memory::CodeCave(PositionLoginDlg, dwLoginCreateDlg, 14);
	Memory::CodeCave(PositionLoginUsername, dwLoginUsername, 11);
	Memory::CodeCave(PositionLoginPassword, dwLoginPassword, 8);
	Memory::WriteInt(dwLoginInputBackgroundColor + 3, 0xFFF8FAFF); // ARGB value
	Memory::WriteByte(dwLoginInputFontColor + 3, 1); // bool: true=black, false=white
	Memory::WriteInt(dwLoginLoginBtn + 1, -127); // x-pos
	Memory::WriteInt(dwLoginFindPasswordBtn + 1, -127); // x-pos
	Memory::WriteInt(dwLoginQuitBtn + 1, -127); // x-pos
	Memory::WriteInt(dwLoginFindIDBtn + 1, -127); // x-pos
	Memory::WriteByte(dwLoginFindIDBtn + 1, -127); // x-pos
	Memory::WriteByte(dwLoginWebHomeBtn + 1, -127); // x-pos
	Memory::WriteByte(dwLoginWebRegisterBtn + 1, -127); // x-pos
}

void Client::FixMouseWheel() {
	Memory::CodeCave(fixMouseWheelHook, 0x009F1AD5, 5);
}

void Client::Chinese() {
	if (Client::imeType == 0)
	{
		FixIme::HookOld();
	}
	else {
		FixIme::HookNew();
	}

	FixBuddy::Hook();
	if (SwitchChinese) {
		// 聊天栏选项
		Memory::WriteString(0x00AF2B28, "对联盟     ");

		// 有效期字体大小
		Memory::WriteByte(0x008E55ED + 1, 0x0B);

		// 属性位置字体大小
		Memory::WriteByte(0x008E557A + 1, 0x0B);
		Memory::WriteByte(0x008E565E + 1, 0x0B);

		// 玩家名片 职业字体大小和位置
		Memory::WriteByte(0x0090142E + 1, 0x5E); // 60->5E 位置上移
		Memory::WriteByte(0x00901400 + 1, 1); // 字体type改为1 对应12号大小
	}
}

void Client::LongQuickSlot() {
	// CUIStatusBar::OnCreate
	Memory::WriteByte(0x008D6547 + 1, 0xF0); // Draw rest of quickslot bar
	Memory::WriteByte(0x008D6547 + 2, 0x03);
	Memory::WriteByte(0x008D6819 + 1, 0xF0); // Draw rest of hotkeys
	Memory::WriteByte(0x008D6819 + 2, 0x03);
	Memory::WriteByte(0x008D6AAB + 1, 0xF0); // Draw rest of cooldowns, who tf knows why. TY Rulax
	Memory::WriteByte(0x008D6AAB + 2, 0x03);

	//----CQuickslotKeyMappedMan::CQuickslotKeyMappedMan?????
	//Memory::WriteInt(0x0072B7CE + 1, (DWORD)&Array_aDefaultQKM_0);  //??
	//Memory::WriteInt(0x0072B8EB + 1, (DWORD)&Array_aDefaultQKM_0);  //??

	//----CUIStatusBar::CQuickSlot::CompareValidateFuncKeyMappedInfo
	Memory::WriteByte(0x008E269D, 0x1A); //increase 8 --> 26
	Memory::WriteByte(0x008E243D, 0x1A); //increase 8 --> 26
	Memory::WriteByte(0x008E2485, 0xBB);
	Memory::WriteInt(0x008E2485 + 1, (DWORD)&Array_Expanded);
	Memory::WriteByte(0x008E2485 + 5, 0x90); //Errant byte
	Memory::WriteByte(0x008E242B, 0xB8);
	Memory::WriteInt(0x008E242B + 1, (DWORD)&Array_Expanded);
	Memory::WriteByte(0x008E242B + 5, 0x90); //Errant Byte

	//----CUIStatusBar::CQuickSlot::Draw
	Memory::WriteByte(0x008E3239 + 3, 0x1A);
	Memory::WriteByte(0x008E2AA5, 0xB8);
	Memory::WriteInt(0x008E2AA5 + 1, (DWORD)&Array_Expanded);
	Memory::FillBytes(0x008E2AA5 + 5, 0x90, 3); // Nopping errant operations

	//----CUIStatusBar::OnMouseMove                  
	Memory::WriteByte(0x008DCA28 + 1, 0x34);
	Memory::WriteByte(0x008DCA28 + 2, 0x85);
	Memory::WriteInt(0x008DCA28 + 3, (DWORD)&Array_Expanded);

	//----CUIStatusBar::CQuickSlot::GetPosByIndex
	Memory::WriteInt(0x008E3428 + 2, (DWORD)&Array_ptShortKeyPos);
	Memory::WriteInt(0x008E3430 + 2, (DWORD)&Array_ptShortKeyPos + 4);
	Memory::WriteByte(0x008E341C + 2, 0x1A); //change cmp 8 --> cmp 26

	//CUIStatusBar::GetShortCutIndexByPos
	Memory::WriteInt(0x008E33CF + 1, (DWORD)&Array_ptShortKeyPos_Fixed_Tooltips + 4);
	Memory::WriteByte(0x008E3401 + 1, 0x3E);

	//CUIStatusBar::CQuickSlot::DrawSkillCooltime
	Memory::WriteByte(0x008E5BE8 + 3, 0x1A);
	Memory::WriteByte(0x008E58E6, 0xBE);
	Memory::WriteInt(0x008E58E6 + 1, (DWORD)&cooldown_Array); //Pass enlarged FFFFF array
	Memory::WriteByte(0x008E58E6 + 5, 0x90); //Errant byte
	Memory::WriteByte(0x008E58EC, 0xBF);
	Memory::WriteInt(0x008E58EC + 1, (DWORD)&Array_Expanded + 1);
	Memory::WriteByte(0x008E58EC + 5, 0x90);

	//----CDraggableMenu::OnDropped   ??
	//Memory::WriteByte(0x004F928A + 2, 0x1A); //change cmp 8 --> cmp 26
	//----CDraggableMenu::MapFuncKey
	Memory::WriteByte(0x00508417 + 2, 0x1A); //change cmp 8 --> cmp 26
	////----CUIKeyConfig::OnDestroy      ??
	//Memory::WriteByte(0x00833797 + 2, 0x6C); // Updates the offset to 108 (triple) (old->24h)    
	//Memory::WriteByte(0x00833841 + 2, 0x6C); // Updates the offset to 108 (triple) (old->24h)
	//Memory::WriteByte(0x00833791 + 1, 0x68); // push 68h (triple)
	//Memory::WriteByte(0x0083383B + 1, 0x68); // push 68h (triple)
	////----CUIKeyConfig::~CUIKeyConfig  ??
	//Memory::WriteByte(0x0083287F + 2, 0x6C); // triple the base value at this hex (old->24h)
	//Memory::WriteByte(0x00832882 + 1, 0x68); // push 68h (triple)
	////----CQuickslotKeyMappedMan::SaveQuickslotKeyMap  ??
	//Memory::WriteByte(0x0072B8C0 + 2, 0x6C); // triple the base value at this hex (old->24h)
	//Memory::WriteByte(0x0072B8A0 + 1, 0x68); // push 68h, (triple) //CQuickslotKeyMappedMan::SaveQuickslotKeyMap
	//Memory::WriteByte(0x0072B8BD + 1, 0x68); // push 68h, (triple) //CQuickslotKeyMappedMan::SaveQuickslotKeyMap
	////----CQuickslotKeyMappedMan::OnInit  ??
	//Memory::WriteByte(0x0072B861 + 1, 0x68); // push 68h (triple) (these ones might have to be just 60)
	//Memory::WriteByte(0x0072B867 + 2, 0x6C); // triple the base value at this hex (old->24h)
	////----CUIKeyConfig::CNoticeDlg::OnChildNotify     ??
	//Memory::WriteByte(0x00836A1E + 1, 0x68); // push 68h (triple)
	//Memory::WriteByte(0x00836A21 + 2, 0x6C); // triple the base value at this hex (old->24h)


	//// CODECAVES CLIENT EDITS ---- 
	Memory::CodeCave(CompareValidateFuncKeyMappedInfo_cave, 0x8E2448, 5);
	//Memory::CodeCave(sub_9FA0CB_cave, 0x9FA0DB, 5);                          //??
	//Memory::CodeCave(sDefaultQuickslotKeyMap_cave, 0x72B7BC, 5);             //??
	//Memory::CodeCave(DefaultQuickslotKeyMap_cave, 0x72B8E6, 5);              //??
	Memory::CodeCave(Restore_Array_Expanded, 0x006282FC, 6); //restores the skill array to 0s
	Memory::CodeCave(DefaultQuickslotKeyMap79_cave, 0x005BA1C6, 7);
}

void Client::FixDateFormat() {
	if (SwitchChinese)
	{
		Memory::CodeCave(fixDateFormat, 0x008EBF57, 14); // StringPool 5273
		Memory::CodeCave(fixDateFormat2, 0x008EBFA1, 14); // StringPool 655
		Memory::CodeCave(fixDateFormat3, 0x008EC31A, 14); // StringPool 679
		Memory::CodeCave(fixDateFormat4, 0x008EBF05, 14); // StringPool 3138
	}
}

void Client::FixItemType() {
	if (SwitchChinese)
	{
		Memory::CodeCave(getItemType1, 0x005CFA99, 15);
		Memory::CodeCave(getItemType2, getItemType2Addr, 27);
	}
}

DWORD Client::jumpCap = 123;
static float climbSpeedSave = 0;
void Client::JumpCap() {
	Memory::CodeCave(customJumpCapHook1, 0x007888E2, 10);
	Memory::CodeCave(customJumpCapHook2, 0x008C9B37, 10);
	Memory::CodeCave(customJumpCapHook3, 0x009541B9, 5);

	Memory::WriteInt(0x009D8158 + 2, (DWORD)&climbSpeedSave);
	if (climbSpeedAuto)
	{
		Memory::CodeCave(calcSpeedHook, 0x009541B3, 6);
	}
	else {
		Memory::WriteDouble((DWORD)&climbSpeedSave, climbSpeed * 3.0);
	}
}

void Client::FixChatPosHook() {
	// 修复聊天窗里的聊天信息偏下的问题
	// Memory::WriteByte(0x008DD05A + 2, 0x4);
	// Memory::WriteByte(0x008DD067 + 2, 0x3);
	// 老方法导致收起聊天框时，显示的信息太偏下了
	Memory::CodeCave(chatTextPos, 0x008DD06F, 6);
}

void Client::CRCBypass() {
	Memory::WriteInt(0x00D02B4B + 1, 0x0752976C);
	Memory::WriteByte(0x00A5A464, 0xC3);
	Memory::WriteInt(0x00A5A949, 0xC3);
	Memory::WriteByte(0x009FE755, 0x75);
}

void Client::NoPassword() {
	if (noPassword)
	{
		Memory::WriteInt(0x0064C529 + 2, 0);
	}
}

void Client::MoreHook() {

	Memory::WriteInt(0x009AFEEE + 1, 480);

	Memory::CodeCave(faceHairCave, 0x005FCEFF, 10);
	Memory::CodeCave(canSendPkgTimeCave, 0x00485169, 10);

	if (talkRepeat)
	{
		Memory::WriteByte(0x004900C9 + 1, 5);
	}
	Memory::WriteInt(0x00490127 + 2, talkTime);

	Memory::WriteInt(0x008CA0C2 + 1, Client::StatBackgrndWidth - 20); // 面板关闭按钮x  176-20
	Memory::WriteInt(0x008CA226 + 1, Client::StatBackgrndWidth); // 面板宽度       176
	Memory::WriteInt(0x008CA780 + 1, Client::StatDetailBackgrndWidthRect); // 详情面板宽度
	Memory::WriteInt(0x00815A5E + 1, Client::StatBackgrndWidth); // 详情面板初始x
	Memory::WriteInt(0x00816786 + 1, Client::StatBackgrndWidth); // 详情面板切换x
	Memory::WriteInt(0x008CD155 + 1, Client::StatBackgrndWidth - 23); // 加属性按钮x    176-23
	Memory::WriteInt(0x008C7FCF + 1, Client::StatDetailBackgrndWidth - 23); // 详情面板关闭按钮x    177 - 23
	Memory::WriteInt(0x008CC2F5 + 1, Client::StatBackgrndWidth); // 移动时详情面板x
	// 偏移面板位置
	Memory::WriteInt(0x008CADD1 + 1, Client::StatBackgrndWidth);
	Memory::WriteInt(0x008CA519 + 1, Client::StatBackgrndWidth);
	statDetailBtnX = Client::StatBackgrndWidth - 52; // 详情按钮 176-52
	Memory::CodeCave(apDetailBtn, 0x008CA489, 7);
	statAutoBtnX = Client::StatBackgrndWidth - 79;   //自动加点 176-79
	Memory::CodeCave(apAutoBtn, 0x008CD3DC, 7);

}

void Client::Skill() {
	//二段跳
	if (Client::s14101004) {
		Memory::CodeCave(doubleJump, 0x00955F51, 5);
	}
	//暗杀
	if (Client::s4221001) {
		Memory::CodeCave(skill4221001, 0x00975369, 5);
	}
	//一出双击
	if (Client::s4221001) {
		byte s4221001[] = { 0xB8,0xFF,0xFF ,0xFF ,0xFF };
		Memory::WriteByteArray(0x0097A28F, s4221001, sizeof(s4221001));
	}
}