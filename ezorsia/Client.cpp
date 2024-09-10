#include "stdafx.h"
#include "AddyLocations.h"
#include "codecaves.h"
#include <cstringt.h>
#include "FixIme.h"
#include "FixBuddy.h"

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
	//if (useTubi) { Memory::FillBytes(0x00485C32, 0x90, 2); }

	//Memory::WriteInt(0x0077E055 + 1, 2147483646); // 物攻PAD 相关具体不明，默认值1999，int 4字节
	//Memory::WriteInt(0x0077E12F + 1, 2147483646); // 技能 相关具体不明，默认值1999，int 4字节
	//Memory::WriteInt(0x008C3304 + 1, setDamageCap); // 物攻面板，默认值199999，int 4字节
	//Memory::WriteInt(0x0077E215 + 1, setMAtkCap); // 魔攻面板，int 4字节
	//Memory::WriteInt(0x00780620 + 1, setMAtkCap); // 魔攻面板，int 4字节
	//Memory::WriteInt(0x007806D0 + 1, setAccCap); // 命中，默认999
	//Memory::WriteInt(0x00780702 + 1, setAvdCap); // 回避，默认999
	//Memory::WriteInt(0x0078FF5F + 1, 2147483646); // 计算物理伤害相关，意义不明，默认1999，int 4字节
	//Memory::WriteInt(0x0079166C + 1, 2147483646); // 计算魔攻MDamage的，默认值1999，int 4字节，注意：这里不改的话，打怪输出计算的魔法伤害就是按1999计算的
	//Memory::WriteInt(0x00791CD5 + 1, 2147483646); // 计算魔攻MDamage的，默认值1999，int 4字节，注意：这里不改似乎也不影响输出计算
	//Memory::WriteInt(0x0078E061 + 1, 2147483646); //CalcDamage::PDamage 999，意义不明，int 4字节
	//Memory::WriteInt(0x0078E67D + 1, 2147483646); //CalcDamage::PDamage 999，意义不明，int 4字节
	//Memory::WriteInt(0x007918FC + 1, 2147483646); //CalcDamage::MDamage 999，意义不明，int 4字节

	//Memory::WriteDouble(0x00AFE8A0, setAtkOutCap);	// 输出显示上限，默认199999，double 8字节


	//Memory::WriteInt(0x00780743 + 3, speedMovementCap); //set speed cap //ty ronan
	//Memory::WriteInt(0x008C4286 + 1, speedMovementCap); //set speed cap //ty ronan
	//Memory::WriteInt(0x0094D91E + 1, speedMovementCap); //set speed cap //ty ronan
}

void Client::UpdateResolution() {
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
	Memory::WriteByte(0x007B9CB9+2, 26);   // 3 + 23                 buff tip y-pos range
	Memory::WriteByte(0x007B9CC2+2, 58);   // 35+23
	Memory::WriteInt(dwTempStatToolTipFind + 3, -m_nGameWidth + 6); //lea eax,[eax+ecx-797] ; CTemporaryStatView::FindIcon
	Memory::WriteByte(0x007B9EA7 + 2, 26);   // 3 + 23                  y-pos cancel range
	Memory::WriteByte(0x007B9EAC + 2, 58);   // 35 + 23
	Memory::WriteInt(dwTempStatIconVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon buff y-pos
	Memory::WriteInt(dwTempStatIconHpos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon buff x-pos
	Memory::WriteInt(dwTempStatCoolTimeVPos + 2, (m_nGameHeight / 2) - 23);	//sub ebx,277 ; Skill icon cooltime y-pos
	Memory::WriteInt(dwTempStatCoolTimeHPos + 3, (m_nGameWidth / 2) - 3);	//lea eax,[eax+esi+397] ; Skill icon cooltime x-pos

	Memory::WriteByte(0x009FC0CB, 0xEB);	//jz 009FC13A ; jmp remove exit ads

	int slotXPos = m_nGameWidth - 540;
	if (m_nGameWidth < 1366) {
		slotXPos = m_nGameWidth > 1024 ? 815 : 805;
	}
	Memory::WriteInt(dwQuickSlotInitVPos + 1, m_nGameHeight + 1);//add eax,533
	Memory::WriteInt(dwQuickSlotInitHPos + 1, slotXPos); //push 647 //hd800
	Memory::WriteInt(dwQuickSlotVPos + 2, m_nGameHeight + 1);//add esi,533
	Memory::WriteInt(dwQuickSlotHPos + 1, slotXPos); //push 647 //hd800
	Memory::WriteInt(dwQuickSlotCWndVPos + 2, -500); //lea edi,[eax-427]
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
	Memory::WriteInt(0x004E7AF7 + 1, m_nGameWidth);                        //->079 004E7AF7 800


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
	Memory::WriteInt(0x008D6D3B + 1, m_nGameHeight - 22);

	Memory::WriteInt(0x008D6D40 + 1, m_nGameWidth);
	Memory::WriteInt(0x008D6FE3 + 1, m_nGameHeight - 22);
	Memory::WriteInt(0x008D6FE8 + 1, m_nGameWidth);    // CUIStatusBar
	Memory::WriteInt(0x0065B4C6 + 1, m_nGameHeight);
	Memory::WriteInt(0x0065B4CB + 1, m_nGameWidth);    // (UI/Logo/Nexon)
	Memory::WriteInt(0x004FD494 + 1, m_nGameWidth);
	Memory::WriteInt(0x004FD483 + 1, m_nGameHeight);                          // CreateWnd
	Memory::WriteInt(0x004FD3E3 + 1, m_nGameWidth);
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
	Memory::WriteInt(0x0062A7DE + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0093B675 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0095DBA3 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0098EE27 + 1, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x0098F84C + 2, floor(-m_nGameHeight / 2));
	Memory::WriteInt(0x00A4EAC9 + 2, floor(-m_nGameHeight / 2));              // CWvsPhysicalSpace2D::Load          //->079 00A4EAC9 || 00A55A79 -300
	Memory::WriteInt(0x0062A922 + 1, floor(-m_nGameHeight / 2));
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

	//Memory::WriteInt(0x007E1E07 + 2, m_nGameWidth);//??related to displaying server message at top of screen
	//Memory::WriteInt(0x007E19CA + 2, m_nGameWidth);//??related to displaying server message at top of screen

	//Memory::WriteInt(0x005362B2 + 1, (m_nGameWidth / 2) - 129);//??related to boss bar
	//Memory::WriteInt(0x005364AA + 2, (m_nGameWidth / 2) - 128);//??related to boss bar

	//Memory::WriteInt(0x00592A08 + 1, (m_nGameWidth / 2) - 125);//??likely related to mouse pos

	//Memory::WriteInt(0x00621226 + 1, (m_nGameWidth / 2) - 216);//??possibly related to logo
	//Memory::WriteByte(0x0062121E + 1, 0x01);//??possibly related to logo

	//Memory::WriteInt(0x008C069F + 1, (m_nGameHeight / 2) - 14);//??related to status bar
	//Memory::WriteInt(0x008C06A4 + 1, (m_nGameWidth / 2) - 158);//???related to status bar

	//Memory::WriteInt(0x00A24D0B + 1, (m_nGameWidth / 2) - 129);//??

	//Memory::WriteInt(0x00BE273C, 128);//??
	//Memory::WriteByte(0x00A5FC2B, 0x05);//??
	////Memory::WriteByte(0x008D1790 + 2, 0x01); //related to quickslots area presence		 originally 1U but changed because unsigned int crashes it after char select
	//Memory::WriteByte(0x0089B636 + 2, 0x01); //related to exp gain/item pick up msg, seems to affect msg height ! originally 1U but changed because unsigned int crashes it after char select
	//Memory::WriteByte(0x00592A06 + 1, 0x01);//???likely related to mouse pos

	//Memory::WriteInt(0x00744EB4 + 1, m_nGameWidth);//??related to in-game taking screenshot functionality
	//Memory::WriteInt(0x00744EB9 + 1, m_nGameHeight);//??related to in-game taking screenshot functionality
	//Memory::WriteInt(0x00744E2A + 1, 3 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality
	//Memory::WriteInt(0x00744E43 + 1, m_nGameWidth* m_nGameHeight);//??related to in-game taking screenshot functionality
	//Memory::WriteInt(0x00744DA6 + 1, 4 * m_nGameWidth * m_nGameHeight);//??related to in-game taking screenshot functionality

	//Memory::WriteInt(0x00897BB4 + 1, (m_nGameWidth / 2) - 143);//??related to exp gain/item pick up msg

	//if (WindowedMode) {
	//	unsigned char forced_window[] = { 0xb8, 0x00, 0x00, 0x00, 0x00 }; //force window mode	//thanks stelmo for showing me how to do this
	//	Memory::WriteByteArray(0x009F7A9B, forced_window, sizeof(forced_window));//force window mode
	//}
	//if (RemoveLogos) {
	//	Memory::FillBytes(0x0062EE54, 0x90, 21);	//no Logo @launch //Thanks Denki!!
	//}

	//int msgAmntOffset, msgAmnt; msgAmnt = MsgAmount; msgAmntOffset = msgAmnt * 14;

	//Memory::WriteInt(0x0089B639 + 1, m_nGameHeight - 6 - msgAmntOffset - 80);//inventory/exp gain y axis //####hd100 //90
	//Memory::WriteInt(0x0089B6F7 + 1, m_nGameWidth - 405);//inventory/exp gain x axis //310 //####hd415 //405

	//Memory::WriteInt(0x0089AF33 + 1, 400);//length of pick up and exp gain message canvas //found with help from Davi
	//Memory::WriteInt(0x0089B2C6 + 1, 400);//address to move the message in the canvas adjusted above to the center of the new canvas  //thanks chris

	//Memory::WriteInt(0x0089AEE2 + 3, msgAmnt);//moregainmsgs part 1
	//MoreGainMsgsOffset = msgAmnt;	//param for ccmoregainmssgs
	//Memory::CodeCave(ccMoreGainMsgs, dwMoreGainMsgs, MoreGainMsgsNOPs); //moregainmsgs part 2
	//MoreGainMsgsFadeOffset = 15000;	//param for ccmoregainmssgsFade
	//Memory::CodeCave(ccMoreGainMsgsFade, dwMoreGainMsgsFade, MoreGainMsgsFadeNOPs); //moregainmsgsFade
	//MoreGainMsgsFade1Offset = 255 * 4 / 3;	//param for ccmoregainmssgsFade
	//Memory::CodeCave(ccMoreGainMsgsFade1, dwMoreGainMsgsFade1, MoreGainMsgsFade1NOPs); //moregainmsgsFade1

	//Memory::WriteInt(0x0045B337 + 1, m_nGameWidth);//related to smega display  //likely screen area where pop up starts for smega
	//Memory::WriteInt(0x0045B417 + 1, m_nGameWidth - 225);//smega with avatar x axis for duration on screen

	//Memory::WriteInt(0x007C2531 + 1, m_nGameHeight - 80);//??


	Memory::WriteInt(0x008581D3 + 1, m_nGameHeight - 198); //system menu pop up
	Memory::WriteInt(0x008589E8 + 1, m_nGameHeight - 281); //shortcuts pop up	//0x84A5BD -  System Options "X" Position. if needed
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
	Memory::CodeCave(fixMouseWheelHook, 0x009E8090, 5);
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
	//Memory::CodeCave(Restore_Array_Expanded, 0x008CFDFD, 6); //restores the skill array to 0s  ??
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

void Client::JumpCap() {
	Memory::CodeCave(customJumpCapHook1, 0x00780797, 10);
	Memory::CodeCave(customJumpCapHook2, 0x008C42A3, 10);
	Memory::CodeCave(customJumpCapHook3, 0x0094D942, 5);


	Memory::WriteInt(0x009CC6F9 + 2, 0x00C1CF80);
	if (climbSpeedAuto)
	{
		Memory::CodeCave(calcSpeedHook, 0x0094D93C, 6);
	}
	else {
		Memory::WriteDouble(0x00C1CF80, climbSpeed * 3.0);
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
	Memory::WriteInt(13642571, 1385655400);
	Memory::WriteInt(10855524, 2179763139);
	Memory::WriteInt(10479445, 2240484469);
	Memory::WriteInt(10856777, 1374456771);
	Memory::WriteInt(7957490, 4294967230);
	//Memory::WriteInt(1987638317, 1797760184);
	//Memory::WriteInt(2001066480, 1797783736);
	//Memory::WriteInt(1987638317, 1797760184);
	//Memory::WriteInt(2001066480, 1797783736);
}

void Client::NoPassword() {
	//if (noPassword && debug)
	//{

		//Memory::WriteInt(1987638317, 1797760184);
		//Memory::WriteInt(2001066480, 1797783736);
	unsigned char CA_009F62E2[] = { 0xEB, 0xCC }; //CWvsApp::Run: nop?
	Memory::WriteByteArray(0x0097642E, CA_009F62E2, sizeof(CA_009F62E2));
	//}
}