; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=AddScore
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WorldCup.h"
LastPage=0

ClassCount=11
Class1=CWorldCupApp
Class2=CWorldCupDoc
Class3=CWorldCupView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_LOOK_TEAM
Resource2=IDD_ADD_TEAM
Resource3=IDD_ADD_MATCH
Resource4=IDD_ADD_PLAYER
Class5=CAboutDlg
Class6=AddTeam
Class7=AddPlayer
Resource5=IDR_MAINFRAME
Class8=LookTeam
Class9=AddMatch
Resource6=IDD_ABOUTBOX
Class10=LookMatch
Resource7=IDD_LOOK_MATCH
Class11=AddScore
Resource8=IDD_ADD_SCORE

[CLS:CWorldCupApp]
Type=0
HeaderFile=WorldCup.h
ImplementationFile=WorldCup.cpp
Filter=N

[CLS:CWorldCupDoc]
Type=0
HeaderFile=WorldCupDoc.h
ImplementationFile=WorldCupDoc.cpp
Filter=N

[CLS:CWorldCupView]
Type=0
HeaderFile=WorldCupView.h
ImplementationFile=WorldCupView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDC_EDIT1


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUSCORE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=WorldCup.cpp
ImplementationFile=WorldCup.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MENUTEAM
Command18=ID_MENUPLAYER
Command19=ID_MENUMATCH
Command20=ID_MENUSCORE
Command21=ID_MENUTEAMINFORMATION
Command22=ID_MENULOOKMATCH
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_LOOK
Command10=ID_TEAMINFORMATION
CommandCount=10

[DLG:IDD_ADD_TEAM]
Type=1
Class=AddTeam
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552

[DLG:IDD_ADD_PLAYER]
Type=1
Class=AddPlayer
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEAM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_NUMBER,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_RANKING,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_POSITION,edit,1350631552

[DLG:IDD_ADD_MATCH]
Type=1
Class=AddMatch
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEAM1,edit,1350631552
Control5=IDC_TEAM2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_WEIGHT1,edit,1350631552
Control9=IDC_WEIGHT2,edit,1350631552
Control10=IDC_STATIC,static,1342308352

[CLS:AddTeam]
Type=0
HeaderFile=AddTeam.h
ImplementationFile=AddTeam.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[CLS:AddPlayer]
Type=0
HeaderFile=AddPlayer.h
ImplementationFile=AddPlayer.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_LOOK_TEAM]
Type=1
Class=LookTeam
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LOOK_TEAM,edit,1350631552

[CLS:LookTeam]
Type=0
HeaderFile=LookTeam.h
ImplementationFile=LookTeam.cpp
BaseClass=CDialog
Filter=D
LastObject=IDTEAM
VirtualFilter=dWC

[CLS:AddMatch]
Type=0
HeaderFile=AddMatch.h
ImplementationFile=AddMatch.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_LOOK_MATCH]
Type=1
Class=LookMatch
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TEAM1,edit,1350631552
Control5=IDC_TEAM2,edit,1350631552
Control6=IDC_STATIC,static,1342308352

[CLS:LookMatch]
Type=0
HeaderFile=LookMatch.h
ImplementationFile=LookMatch.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TEAM1

[DLG:IDD_ADD_SCORE]
Type=1
Class=AddScore
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TEAM,edit,1350631552
Control7=IDC_PLAYER,edit,1350631552
Control8=IDC_TIMING,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_AGAINST,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PLAYER2,edit,1350631552

[CLS:AddScore]
Type=0
HeaderFile=AddScore.h
ImplementationFile=AddScore.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PLAYER2
VirtualFilter=dWC

