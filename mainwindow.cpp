#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    zoneCentrale = new QMdiArea;

    // A great thank to gasetta for explaining how this work : http://casetta.tuxfamily.org/
    rawEquiv[QString(QChar(247))+QString(QChar(204))]="\\DrawOn";
    rawEquiv[QString(QChar(247))+QString(QChar(220))]="\\DrawOff";
    rawEquiv[QString(QChar(247))+QString(QChar(74))]="\\S-Gph1 ";
    rawEquiv[QString(QChar(247))+QString(QChar(75))]="\\S-Gph2 ";
    rawEquiv[QString(QChar(247))+QString(QChar(76))]="\\S-Gph3 ";
    rawEquiv[QString(QChar(247))+QString(QChar(80))]="\\Scatter";
    rawEquiv[QString(QChar(247))+QString(QChar(81))]="\\xyLine";
    rawEquiv[QString(QChar(247))+QString(QChar(82))]="\\Hist";
    rawEquiv[QString(QChar(247))+QString(QChar(83))]="\\MedBox";
    rawEquiv[QString(QChar(247))+QString(QChar(84))]="\\MeanBox";
    rawEquiv[QString(QChar(247))+QString(QChar(85))]="\\N-Dist";
    rawEquiv[QString(QChar(247))+QString(QChar(86))]="\\Broken";
    rawEquiv[QString(QChar(247))+QString(QChar(87))]="\\Linear";
    rawEquiv[QString(QChar(247))+QString(QChar(88))]="\\Med-Med";
    rawEquiv[QString(QChar(247))+QString(QChar(89))]="\\Quad";
    rawEquiv[QString(QChar(247))+QString(QChar(90))]="\\Cubic";
    rawEquiv[QString(QChar(247))+QString(QChar(91))]="\\Quart";
    rawEquiv[QString(QChar(247))+QString(QChar(92))]="\\Log";
    rawEquiv[QString(QChar(247))+QString(QChar(93))]="\\Exp";
    rawEquiv[QString(QChar(247))+QString(QChar(94))]="\\Power";
    rawEquiv[QString(QChar(127))+QString(QChar(106))]="\\List1";
    rawEquiv[QString(QChar(127))+QString(QChar(107))]="\\List2";
    rawEquiv[QString(QChar(127))+QString(QChar(108))]="\\List3";
    rawEquiv[QString(QChar(127))+QString(QChar(109))]="\\List4";
    rawEquiv[QString(QChar(127))+QString(QChar(110))]="\\List5";
    rawEquiv[QString(QChar(127))+QString(QChar(111))]="\\List6";
    rawEquiv[QString(QChar(247))+QString(QChar(77))]="\\Square";
    rawEquiv[QString(QChar(247))+QString(QChar(78))]="\\Cross";
    rawEquiv[QString(QChar(247))+QString(QChar(79))]="\\Dot";
    rawEquiv[QString(QChar(127))+QString(QChar(53))]="\\Blue ";
    rawEquiv[QString(QChar(127))+QString(QChar(52))]="\\Orange ";
    rawEquiv[QString(QChar(127))+QString(QChar(54))]="\\Green ";
    rawEquiv[QString(QChar(247))+QString(QChar(64))]="\\1-Variable ";
    rawEquiv[QString(QChar(247))+QString(QChar(65))]="\\2-Variable ";
    rawEquiv[QString(QChar(247))+QString(QChar(66))]="\\LinearReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(67))]="\\Med-MedLine ";
    rawEquiv[QString(QChar(247))+QString(QChar(68))]="\\QuadReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(69))]="\\CubicReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(70))]="\\QuartReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(71))]="\\LogReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(72))]="\\ExpReg ";
    rawEquiv[QString(QChar(247))+QString(QChar(73))]="\\PowerReg ";
    rawEquiv[QString(QChar(127))+QString(QChar(69))]="\\Swap(";
    rawEquiv[QString(QChar(127))+QString(QChar(66))]="\\*Row(";
    rawEquiv[QString(QChar(127))+QString(QChar(67))]="\\*Row+(";
    rawEquiv[QString(QChar(127))+QString(QChar(68))]="\\Row+(";
    rawEquiv[QString(QChar(247))+QString(QChar(176))]="\\SortA(";
    rawEquiv[QString(QChar(247))+QString(QChar(177))]="\\SortD(";
    rawEquiv[QString(QChar(247))+QString(QChar(200))]="\\G SelOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(216))]="\\G SelOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(99))]="\\Y=Type";
    rawEquiv[QString(QChar(247))+QString(QChar(100))]="\\r=Type";
    rawEquiv[QString(QChar(247))+QString(QChar(101))]="\\ParamType";
    rawEquiv[QString(QChar(247))+QString(QChar(103))]="\\X=cType";
    rawEquiv[QString(QChar(247))+QString(QChar(106))]="\\Y>Type";
    rawEquiv[QString(QChar(247))+QString(QChar(107))]="\\Y<Type";
    rawEquiv[QString(QChar(247))+QString(QChar(108))]="\\Y>=Type";
    rawEquiv[QString(QChar(247))+QString(QChar(109))]="\\Y<=Type";
    rawEquiv[QString(QChar(127))+QString(QChar(56))]="\\BlueG ";
    rawEquiv[QString(QChar(127))+QString(QChar(55))]="\\OrangeG ";
    rawEquiv[QString(QChar(127))+QString(QChar(57))]="\\GreenG ";
    rawEquiv[QString(QChar(247))+QString(QChar(149))]="\\StoGMEM ";
    rawEquiv[QString(QChar(247))+QString(QChar(150))]="\\RclGMEM ";
    rawEquiv[QString(QChar(247))+QString(QChar(202))]="\\D SelOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(218))]="\\D SelOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(128))]="\\D Var ";
    rawEquiv[QString(QChar(247))+QString(QChar(101))]="\\ParamType";
    rawEquiv[QString(QChar(247))+QString(QChar(201))]="\\T SelOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(217))]="\\T SelOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(203))]="\\R SelOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(219))]="\\R SelOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(144))]="\\aRanType";
    rawEquiv[QString(QChar(247))+QString(QChar(145))]="a\\R n+Type";
    rawEquiv[QString(QChar(127))+QString(QChar(163))]="\\R n";
    rawEquiv[QString(QChar(127))+QString(QChar(160))]="a\\R n";
    rawEquiv[QString(QChar(127))+QString(QChar(161))]="a\\R n+";
    rawEquiv[QString(QChar(127))+QString(QChar(167))]="b\\R n";
    rawEquiv[QString(QChar(127))+QString(QChar(168))]="b\\R n+1";

    rawEquiv[QString(QChar(127))+QString(QChar(81))]="\\List ";
    rawEquiv[QString(QChar(127))+QString(QChar(74))]="\\List->Mat(";
    rawEquiv[QString(QChar(127))+QString(QChar(70))]="\\Dim ";
    rawEquiv[QString(QChar(127))+QString(QChar(71))]="\\Fill(";
    rawEquiv[QString(QChar(127))+QString(QChar(44))]="\\Seq(";
    rawEquiv[QString(QChar(127))+QString(QChar(153))]="\\Min(";
    rawEquiv[QString(QChar(127))+QString(QChar(32))]="\\Max(";
    rawEquiv[QString(QChar(127))+QString(QChar(46))]="\\Mean(";
    rawEquiv[QString(QChar(127))+QString(QChar(47))]="\\Median(";
    rawEquiv[QString(QChar(127))+QString(QChar(76))]="\\Sum ";
    rawEquiv[QString(QChar(127))+QString(QChar(77))]="\\Prod ";
    rawEquiv[QString(QChar(127))+QString(QChar(79))]="\\Cuml ";
    rawEquiv[QString(QChar(127))+QString(QChar(78))]="\\Percent ";
    rawEquiv[QString(QChar(127))+QString(QChar(64))]="\\Mat ";
    rawEquiv[QString(QChar(127))+QString(QChar(75))]="\\Mat->List(";
    rawEquiv[QString(QChar(127))+QString(QChar(33))]="\\Det ";
    rawEquiv[QString(QChar(127))+QString(QChar(65))]="\\Trn ";
    rawEquiv[QString(QChar(127))+QString(QChar(73))]="\\Augment(";
    rawEquiv[QString(QChar(127))+QString(QChar(72))]="\\Identity ";
    rawEquiv[QString(QChar(127))+QString(QChar(80))]="\\{i}";
    rawEquiv[QString(QChar(127))+QString(QChar(34))]="\\Arg ";
    rawEquiv[QString(QChar(127))+QString(QChar(35))]="\\Conj ";
    rawEquiv[QString(QChar(127))+QString(QChar(36))]="\\ReP ";
    rawEquiv[QString(QChar(127))+QString(QChar(37))]="\\ImP ";
    rawEquiv[QString(QChar(127))+QString(QChar(40))]="\\Solve(";
    rawEquiv[QString(QChar(127))+QString(QChar(38))]="\\d/dx(";
    rawEquiv[QString(QChar(127))+QString(QChar(39))]="\\d2/dxc(";
    rawEquiv[QString(QChar(127))+QString(QChar(42))]="\\FMin(";
    rawEquiv[QString(QChar(127))+QString(QChar(43))]="\\FMax(";
    rawEquiv[QString(QChar(127))+QString(QChar(41))]="\\Sum(";
    rawEquiv[QString(QChar(127))+QString(QChar(52))]="\\Orange ";
    rawEquiv[QString(QChar(127))+QString(QChar(54))]="\\Green ";
    rawEquiv[QString(QChar(247))+QString(QChar(147))]="\\StoPict ";
    rawEquiv[QString(QChar(247))+QString(QChar(148))]="\\RclPict ";
    rawEquiv[QString(QChar(127))+QString(QChar(176))]="\\ And ";
    rawEquiv[QString(QChar(127))+QString(QChar(177))]="\\ Or ";
    rawEquiv[QString(QChar(127))+QString(QChar(179))]="\\Not ";

    rawEquiv[QString(QChar(247))+QString(QChar(0))]="\\If ";
    rawEquiv[QString(QChar(247))+QString(QChar(1))]="\\Then ";
    rawEquiv[QString(QChar(247))+QString(QChar(2))]="\\Else ";
    rawEquiv[QString(QChar(247))+QString(QChar(3))]="\\IfEnd";
    rawEquiv[QString(QChar(247))+QString(QChar(4))]="\\For ";
    rawEquiv[QString(QChar(247))+QString(QChar(5))]="\\To ";
    rawEquiv[QString(QChar(247))+QString(QChar(6))]="\\Step ";
    rawEquiv[QString(QChar(247))+QString(QChar(7))]="\\Next ";
    rawEquiv[QString(QChar(247))+QString(QChar(8))]="\\While ";
    rawEquiv[QString(QChar(247))+QString(QChar(9))]="\\WhileEnd";
    rawEquiv[QString(QChar(247))+QString(QChar(10))]="\\Do";
    rawEquiv[QString(QChar(247))+QString(QChar(11))]="\\LpWhile ";
    rawEquiv[QString(QChar(247))+QString(QChar(12))]="\\Return";
    rawEquiv[QString(QChar(247))+QString(QChar(13))]="\\Break";
    rawEquiv[QString(QChar(247))+QString(QChar(14))]="\\Stop";
    rawEquiv[QString(QChar(247))+QString(QChar(24))]="\\ClrText";
    rawEquiv[QString(QChar(247))+QString(QChar(25))]="\\ClrGraph";
    rawEquiv[QString(QChar(247))+QString(QChar(26))]="\\ClrList";
    rawEquiv[QString(QChar(247))+QString(QChar(35))]="\\DrawStat";
    rawEquiv[QString(QChar(247))+QString(QChar(32))]="\\DrawGraph";
    rawEquiv[QString(QChar(247))+QString(QChar(34))]="\\DrawDyna";
    rawEquiv[QString(QChar(247))+QString(QChar(46))]="\\DispF-Tbl";
    rawEquiv[QString(QChar(247))+QString(QChar(36))]="\\DrawFTG-Con";
    rawEquiv[QString(QChar(247))+QString(QChar(37))]="\\DrawFTG-Plt";
    rawEquiv[QString(QChar(247))+QString(QChar(47))]="\\DispR-Tbl";
    rawEquiv[QString(QChar(247))+QString(QChar(42))]="\\DrawWeb ";
    rawEquiv[QString(QChar(247))+QString(QChar(38))]="\\DrawR-Con";
    rawEquiv[QString(QChar(247))+QString(QChar(40))]="\\DrawR-SumCon";
    rawEquiv[QString(QChar(247))+QString(QChar(39))]="\\DrawR-Plt";
    rawEquiv[QString(QChar(247))+QString(QChar(41))]="\\DrawR-SumPlt";
    rawEquiv[QString(QChar(247))+QString(QChar(16))]="\\Locate ";
    rawEquiv[QString(QChar(127))+QString(QChar(143))]="\\Getkey";
    rawEquiv[QString(QChar(247))+QString(QChar(17))]="\\Send(";
    rawEquiv[QString(QChar(247))+QString(QChar(18))]="\\Receive(";

    rawEquiv[QString(QChar(247))+QString(QChar(151))]="\\StoV-Win ";
    rawEquiv[QString(QChar(247))+QString(QChar(152))]="\\RclV-Win ";
    rawEquiv[QString(QChar(247))+QString(QChar(160))]="\\Tangent ";
    rawEquiv[QString(QChar(247))+QString(QChar(161))]="\\Normal ";
    rawEquiv[QString(QChar(247))+QString(QChar(162))]="\\Inverse ";
    rawEquiv[QString(QChar(247))+QString(QChar(98))]="\\Graph X=";
    rawEquiv[QString(QChar(247))+QString(QChar(168))]="\\PlotOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(169))]="\\PlotOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(170))]="\\PlotChg ";
    rawEquiv[QString(QChar(247))+QString(QChar(167))]="\\F-Line ";
    rawEquiv[QString(QChar(247))+QString(QChar(166))]="\\Circle ";
    rawEquiv[QString(QChar(247))+QString(QChar(163))]="\\Vertical ";
    rawEquiv[QString(QChar(247))+QString(QChar(164))]="\\Horizontal ";
    rawEquiv[QString(QChar(247))+QString(QChar(165))]="\\Text ";
    rawEquiv[QString(QChar(247))+QString(QChar(171))]="\\PxlOn ";
    rawEquiv[QString(QChar(247))+QString(QChar(172))]="\\PxlOff ";
    rawEquiv[QString(QChar(247))+QString(QChar(173))]="\\PxlChg ";
    rawEquiv[QString(QChar(247))+QString(QChar(175))]="\\PxlTest ";

    rawEquiv[QString(QChar(247))+QString(QChar(195))]="\\CoordOn";
    rawEquiv[QString(QChar(247))+QString(QChar(211))]="\\CoordOff";
    rawEquiv[QString(QChar(247))+QString(QChar(125))]="\\GridOn";
    rawEquiv[QString(QChar(247))+QString(QChar(122))]="\\GridOff";
    rawEquiv[QString(QChar(247))+QString(QChar(194))]="\\AxesOn";
    rawEquiv[QString(QChar(247))+QString(QChar(210))]="\\AxesOff";
    rawEquiv[QString(QChar(247))+QString(QChar(196))]="\\LabelOn";
    rawEquiv[QString(QChar(247))+QString(QChar(212))]="\\LabelOff";
    rawEquiv[QString(QChar(127))+QString(QChar(50))]="\\P/L-Blue";
    rawEquiv[QString(QChar(127))+QString(QChar(49))]="\\P/L-Orange";
    rawEquiv[QString(QChar(127))+QString(QChar(51))]="\\P/L-Green";
    rawEquiv[QString(QChar(247))+QString(QChar(112))]="\\G-Connect";
    rawEquiv[QString(QChar(247))+QString(QChar(113))]="\\G-Plot";
    rawEquiv[QString(QChar(247))+QString(QChar(197))]="\\DerivOn";
    rawEquiv[QString(QChar(247))+QString(QChar(213))]="\\DerivOff";
    rawEquiv[QString(QChar(247))+QString(QChar(120))]="\\BG-None";
    rawEquiv[QString(QChar(247))+QString(QChar(121))]="\\BG-Pict ";
    rawEquiv[QString(QChar(247))+QString(QChar(192))]="\\FuncOn";
    rawEquiv[QString(QChar(247))+QString(QChar(208))]="\\FuncOff";
    rawEquiv[QString(QChar(247))+QString(QChar(193))]="\\SimulOn";
    rawEquiv[QString(QChar(247))+QString(QChar(209))]="\\SimulOff";
    rawEquiv[QString(QChar(247))+QString(QChar(96))]="\\S-WindAuto";
    rawEquiv[QString(QChar(247))+QString(QChar(97))]="\\S-WindMan";
    rawEquiv[QString(QChar(247))+QString(QChar(184))]="\\File1";
    rawEquiv[QString(QChar(247))+QString(QChar(185))]="\\File2";
    rawEquiv[QString(QChar(247))+QString(QChar(186))]="\\File3";
    rawEquiv[QString(QChar(247))+QString(QChar(187))]="\\File4";
    rawEquiv[QString(QChar(247))+QString(QChar(188))]="\\File5";
    rawEquiv[QString(QChar(247))+QString(QChar(189))]="\\File6";
    rawEquiv[QString(QChar(247))+QString(QChar(198))]="\\LocusOn";
    rawEquiv[QString(QChar(247))+QString(QChar(214))]="\\LocusOff";
    rawEquiv[QString(QChar(247))+QString(QChar(136))]="\\VarRange";
    rawEquiv[QString(QChar(247))+QString(QChar(178))]="\\VarList1";
    rawEquiv[QString(QChar(247))+QString(QChar(179))]="\\VarList2";
    rawEquiv[QString(QChar(247))+QString(QChar(180))]="\\VarList3";
    rawEquiv[QString(QChar(247))+QString(QChar(181))]="\\VarList4";
    rawEquiv[QString(QChar(247))+QString(QChar(182))]="\\VarList5";
    rawEquiv[QString(QChar(247))+QString(QChar(183))]="\\VarList6";
    rawEquiv[QString(QChar(247))+QString(QChar(199))]="\\SumDispOn";
    rawEquiv[QString(QChar(247))+QString(QChar(215))]="\\SumDispOff";

    rawEquiv[QString(QChar(127))+QString(QChar(0))]="\\Xmin";
    rawEquiv[QString(QChar(127))+QString(QChar(1))]="\\Xmax";
    rawEquiv[QString(QChar(127))+QString(QChar(2))]="\\Xscl";
    rawEquiv[QString(QChar(127))+QString(QChar(4))]="\\Ymin";
    rawEquiv[QString(QChar(127))+QString(QChar(5))]="\\Ymax";
    rawEquiv[QString(QChar(127))+QString(QChar(6))]="\\Yscl";
    rawEquiv[QString(QChar(127))+QString(QChar(8))]="\\Tmin";
    rawEquiv[QString(QChar(127))+QString(QChar(9))]="\\Tmax";
    rawEquiv[QString(QChar(127))+QString(QChar(10))]="\\Tptch";
    rawEquiv[QString(QChar(127))+QString(QChar(16))]="\\RightXmin";
    rawEquiv[QString(QChar(127))+QString(QChar(17))]="\\RightXmax";
    rawEquiv[QString(QChar(127))+QString(QChar(18))]="\\RightXscl";
    rawEquiv[QString(QChar(127))+QString(QChar(20))]="\\RightYmin";
    rawEquiv[QString(QChar(127))+QString(QChar(21))]="\\RightYmax";
    rawEquiv[QString(QChar(127))+QString(QChar(22))]="\\RightYscl";
    rawEquiv[QString(QChar(127))+QString(QChar(24))]="\\RightTmin";
    rawEquiv[QString(QChar(127))+QString(QChar(25))]="\\RightTmax";
    rawEquiv[QString(QChar(127))+QString(QChar(26))]="\\RightTptch";
    rawEquiv[QString(QChar(127))+QString(QChar(11))]="\\Xfct";
    rawEquiv[QString(QChar(127))+QString(QChar(12))]="\\Yfct";
    rawEquiv[QString(QChar(127))+QString(QChar(118))]="\\Q1";
    rawEquiv[QString(QChar(127))+QString(QChar(119))]="\\Q3";
    rawEquiv[QString(QChar(127))+QString(QChar(120))]="\\x1";
    rawEquiv[QString(QChar(127))+QString(QChar(122))]="\\x2";
    rawEquiv[QString(QChar(127))+QString(QChar(124))]="\\x3";
    rawEquiv[QString(QChar(127))+QString(QChar(121))]="\\y1";
    rawEquiv[QString(QChar(127))+QString(QChar(123))]="\\y2";
    rawEquiv[QString(QChar(127))+QString(QChar(125))]="\\y3";
    rawEquiv[QString(QChar(127))+QString(QChar(240))]="\\Y ";
    rawEquiv[QString(QChar(127))+QString(QChar(241))]="\\{r} ";
    rawEquiv[QString(QChar(127))+QString(QChar(242))]="\\Xt ";
    rawEquiv[QString(QChar(127))+QString(QChar(243))]="\\Yt ";
    rawEquiv[QString(QChar(127))+QString(QChar(13))]="\\D Start";
    rawEquiv[QString(QChar(127))+QString(QChar(14))]="\\D End";
    rawEquiv[QString(QChar(127))+QString(QChar(15))]="\\D pitch";
    rawEquiv[QString(QChar(127))+QString(QChar(145))]="\\F Start";
    rawEquiv[QString(QChar(127))+QString(QChar(146))]="\\F End";
    rawEquiv[QString(QChar(127))+QString(QChar(147))]="\\F pitch";
    rawEquiv[QString(QChar(127))+QString(QChar(144))]="\\F Result";
    rawEquiv[QString(QChar(127))+QString(QChar(160))]="a\\R n";
    rawEquiv[QString(QChar(127))+QString(QChar(161))]="a\\R n+";
    rawEquiv[QString(QChar(127))+QString(QChar(167))]="b\\R n";
    rawEquiv[QString(QChar(127))+QString(QChar(168))]="b\\R n+";
    rawEquiv[QString(QChar(127))+QString(QChar(149))]="\\R Start";
    rawEquiv[QString(QChar(127))+QString(QChar(150))]="\\R End";
    rawEquiv[QString(QChar(127))+QString(QChar(173))]="a\\R nStart";
    rawEquiv[QString(QChar(127))+QString(QChar(174))]="b\\R nStart";
    rawEquiv[QString(QChar(127))+QString(QChar(148))]="\\R Result";
    rawEquiv[QString(QChar(127))+QString(QChar(98))]="\\Sim Result";
    rawEquiv[QString(QChar(127))+QString(QChar(96))]="\\Sim Coef";
    rawEquiv[QString(QChar(127))+QString(QChar(99))]="\\Ply Result";
    rawEquiv[QString(QChar(127))+QString(QChar(97))]="\\Ply Coef";

    rawEquiv[QString(QChar(134))]="\\sqrt";
    rawEquiv[QString(QChar(139))]="\\x^2";
    rawEquiv[QString(QChar(184))]="\\xrt";
    rawEquiv[QString(QChar(206))]="\\theta";
    rawEquiv[QString(QChar(181))]="\\10^x";
    rawEquiv[QString(QChar(149))]="\\log ";
    rawEquiv[QString(QChar(165))]="\\e^x";
    rawEquiv[QString(QChar(145))]="\\asin ";
    rawEquiv[QString(QChar(129))]="\\sin ";
    rawEquiv[QString(QChar(146))]="\\acos ";
    rawEquiv[QString(QChar(130))]="\\cos ";
    rawEquiv[QString(QChar(147))]="\\atan ";
    rawEquiv[QString(QChar(131))]="\\tan ";
    rawEquiv[QString(QChar(187))]="\\ab/c";
    rawEquiv[QString(QChar(150))]="\\curt";
    rawEquiv[QString(QChar(14))]="\\->";
    rawEquiv[QString(QChar(208))]="\\Pi";
    rawEquiv[QString(QChar(192))]="\\Ans";
    rawEquiv[QString(QChar(15))]="\\EE";
    rawEquiv[QString(QChar(135))]="\\(-)";
    rawEquiv[QString(QChar(133))]="\\In ";
    rawEquiv[QString(QChar(151))]="\\Abs ";
    rawEquiv[QString(QChar(141))]="\\Integral(";
    rawEquiv[QString(QChar(203))]="\\Eox";
    rawEquiv[QString(QChar(204))]="\\Eoy";
    rawEquiv[QString(QChar(161))]="\\sinh ";
    rawEquiv[QString(QChar(162))]="\\cosh ";
    rawEquiv[QString(QChar(163))]="\\tanh ";
    rawEquiv[QString(QChar(177))]="\\asinh ";
    rawEquiv[QString(QChar(178))]="\\acosh ";
    rawEquiv[QString(QChar(179))]="\\atanh ";
    rawEquiv[QString(QChar(171))]="!";
    rawEquiv[QString(QChar(136))]="\\nPr";
    rawEquiv[QString(QChar(152))]="\\nCr";
    rawEquiv[QString(QChar(193))]="\\Ran#";
    rawEquiv[QString(QChar(251))]="\\ProbP(";
    rawEquiv[QString(QChar(252))]="\\ProbQ(";
    rawEquiv[QString(QChar(253))]="\\ProbR(";
    rawEquiv[QString(QChar(254))]="\\ProbT(";
    rawEquiv[QString(QChar(151))]="\\Abs ";
    rawEquiv[QString(QChar(166))]="\\Int ";
    rawEquiv[QString(QChar(182))]="\\Frac ";
    rawEquiv[QString(QChar(211))]="\\Rnd";
    rawEquiv[QString(QChar(222))]="\\Intg ";
    rawEquiv[QString(QChar(156))]="\\Deg>";
    rawEquiv[QString(QChar(172))]="\\Rad>";
    rawEquiv[QString(QChar(188))]="\\Gra>";
    rawEquiv[QString(QChar(140))]="\\Dms";
    rawEquiv[QString(QChar(128))]="\\Pol(";
    rawEquiv[QString(QChar(160))]="\\Rec(";
    rawEquiv[QString(QChar(5))]="\\milli";
    rawEquiv[QString(QChar(4))]="\\micro";
    rawEquiv[QString(QChar(3))]="\\nano";
    rawEquiv[QString(QChar(2))]="\\pico";
    rawEquiv[QString(QChar(1))]="\\fempto";
    rawEquiv[QString(QChar(6))]="\\kilo";
    rawEquiv[QString(QChar(7))]="\\Mega";
    rawEquiv[QString(QChar(8))]="\\Giga";
    rawEquiv[QString(QChar(9))]="\\Tera";
    rawEquiv[QString(QChar(10))]="\\Peta";
    rawEquiv[QString(QChar(11))]="\\Exa";
    rawEquiv[QString(QChar(20))]="\\f1";
    rawEquiv[QString(QChar(21))]="\\f2";
    rawEquiv[QString(QChar(22))]="\\f3";
    rawEquiv[QString(QChar(23))]="\\f4";
    rawEquiv[QString(QChar(24))]="\\f5";
    rawEquiv[QString(QChar(25))]="\\f6";
    rawEquiv[QString(QChar(237))]="\\Prog ";
    rawEquiv[QString(QChar(226))]="\\Lbl ";
    rawEquiv[QString(QChar(236))]="\\Goto";
    rawEquiv[QString(QChar(19))]="\\=>";
    rawEquiv[QString(QChar(233))]="\\Isz ";
    rawEquiv[QString(QChar(232))]="\\Dsz ";
    rawEquiv[QString(QChar(63))]="?";
    rawEquiv[QString(QChar(12))]="\\Disp";
    rawEquiv[QString(QChar(17))]="\\<>";
    rawEquiv[QString(QChar(18))]="\\>=";
    rawEquiv[QString(QChar(16))]="\\<=";
    rawEquiv[QString(QChar(58))]=":";
    rawEquiv[QString(QChar(234))]="\\Factor ";
    rawEquiv[QString(QChar(235))]="\\ViewWindow ";
    rawEquiv[QString(QChar(209))]="\\Cls";
    rawEquiv[QString(QChar(238))]="\\Graph Y=";
    rawEquiv[QString(QChar(244))]="\\Graph r=";
    rawEquiv[QString(QChar(245))]="\\Graph (X,Y)=(";
    rawEquiv[QString(QChar(239))]="\\Graph Integral ";
    rawEquiv[QString(QChar(240))]="\\Graph Y>";
    rawEquiv[QString(QChar(241))]="\\Graph Y<";
    rawEquiv[QString(QChar(242))]="\\Graph Y>=";
    rawEquiv[QString(QChar(243))]="\\Graph Y<=";
    rawEquiv[QString(QChar(224))]="\\Plot ";
    rawEquiv[QString(QChar(225))]="\\Line";
    rawEquiv[QString(QChar(218))]="\\Deg";
    rawEquiv[QString(QChar(219))]="\\Rad";
    rawEquiv[QString(QChar(220))]="\\Gra";
    rawEquiv[QString(QChar(227))]="\\Fix ";
    rawEquiv[QString(QChar(228))]="\\Sci ";
    rawEquiv[QString(QChar(217))]="\\Norm";
    rawEquiv[QString(QChar(221))]="\\Eng";
    rawEquiv[QString(QChar(159))]="\\Sumx";
    rawEquiv[QString(QChar(143))]="\\Sumx2";
    rawEquiv[QString(QChar(196))]="\\Sdx";
    rawEquiv[QString(QChar(197))]="\\Sdxn";
    rawEquiv[QString(QChar(174))]="\\minX";
    rawEquiv[QString(QChar(190))]="\\maxX";
    rawEquiv[QString(QChar(195))]="\\Meany";
    rawEquiv[QString(QChar(207))]="\\Sumy";
    rawEquiv[QString(QChar(191))]="\\Sumy2";
    rawEquiv[QString(QChar(223))]="\\Sumxy";
    rawEquiv[QString(QChar(198))]="\\Sdy";
    rawEquiv[QString(QChar(199))]="\\Sdyn";
    rawEquiv[QString(QChar(173))]="\\minY";
    rawEquiv[QString(QChar(189))]="\\maxY";
    rawEquiv[QString(QChar(158))]="\\Med";
    rawEquiv[QString(QChar(142))]="\\Mo";
    rawEquiv[QString(QChar(175))]="\\Cnt";
    rawEquiv[QString(QChar(202))]="\\Cor";
    rawEquiv[QString(QChar(205))]="\\r";
    rawEquiv[QString(QChar(26))] = "\\hA";
    rawEquiv[QString(QChar(27))] = "\\hB";
    rawEquiv[QString(QChar(28))] = "\\hC";
    rawEquiv[QString(QChar(29))] = "\\hD";
    rawEquiv[QString(QChar(30))] = "\\hE";
    rawEquiv[QString(QChar(31))] = "\\hF";
    rawEquiv[QString(QChar(148))] = "\\Dec>";
    rawEquiv[QString(QChar(132))] = "\\Hex>";
    rawEquiv[QString(QChar(180))] = "\\Bin>";
    rawEquiv[QString(QChar(164))] = "\\Oct>";
    rawEquiv[QString(QChar(183))] = "\\Neg ";
    rawEquiv[QString(QChar(167))] = "\\ Not ";
    rawEquiv[QString(QChar(186))] = "\\and";
    rawEquiv[QString(QChar(170))] = "\\or";
    rawEquiv[QString(QChar(154))] = "\\xor";
    rawEquiv[QString(QChar(138))] = "\\xnor";
    rawEquiv[QString(QChar(212))] = "\\Dec";
    rawEquiv[QString(QChar(213))] = "\\Hex";
    rawEquiv[QString(QChar(214))] = "\\Bin";
    rawEquiv[QString(QChar(215))] = "\\Oct";

    rawEquiv[QString(QChar(168))]="^";
    rawEquiv[QString(QChar(169))]="*";
    rawEquiv[QString(QChar(185))]="/";
    rawEquiv[QString(QChar(137))]="+";
    rawEquiv[QString(QChar(153))]="-";
    rawEquiv[QString(QChar(61))]="=";
    rawEquiv[QString(QChar(62))]=">";
    rawEquiv[QString(QChar(60))]="<";

    keywordPatterns << "^If " << "^Then " << "^Else " << "^IfEnd$"
                    << "^While " << "^WhileEnd$" << "^Do$" << "^LpWhile "
                    << "^For " << " To " << " Step " << "^Next$"
                    << "\\bLocate " << "\\bText " << "\\bList " << "\\bMat ";

    specialCharsPatterns << "\\\\sin " << "sin "
                         << "\\\\micro" << "µ"
                         << "\\\\pi" << "??"
                         << "\\\\sqrt" << "?";

    // ==========
    // == MENU ==
    // ==========

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        QAction *actionNouveauProjet = new QAction(QIcon::fromTheme("document-new"), "Nouveau &Projet", this);
        menuFichier->addAction(actionNouveauProjet);
        actionNouveauProjet->setShortcut(QKeySequence("Ctrl+Shift+N"));

        QAction *actionNouveauProgramme = new QAction(QIcon::fromTheme("document-new"), "&Nouveau Programme", this);
        menuFichier->addAction(actionNouveauProgramme);
        actionNouveauProgramme->setDisabled(true);
        actionNouveauProgramme->setShortcut(QKeySequence("Ctrl+N"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionNouveauProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionFermerProjet = new QAction(QIcon::fromTheme("window-close"), "Fermer le Projet", this);
        menuFichier->addAction(actionFermerProjet);
        actionFermerProjet->setDisabled(true);
        actionFermerProjet->setShortcut(QKeySequence("Ctrl+Shift+W"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionFermerProjet, SLOT(setEnabled(bool)));

        QAction *actionFermerProgramme = new QAction(QIcon::fromTheme("window-close"), "Fermer le Programme", this);
        menuFichier->addAction(actionFermerProgramme);
        actionFermerProgramme->setDisabled(true);
        actionFermerProgramme->setShortcut(QKeySequence("Ctrl+W"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionFermerProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionEnregistrerProjet = new QAction(QIcon::fromTheme("document-save"), "&Enregistrer le Projet", this);
        menuFichier->addAction(actionEnregistrerProjet);
        actionEnregistrerProjet->setDisabled(true);
        actionEnregistrerProjet->setShortcut(QKeySequence("Ctrl+Shift+S"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionEnregistrerProjet, SLOT(setEnabled(bool)));

        QAction *actionEnregistrerProgramme = new QAction(QIcon::fromTheme("document-save"), "En&registrer un Programme", this);
        menuFichier->addAction(actionEnregistrerProgramme);
        actionEnregistrerProgramme->setDisabled(true);
        actionEnregistrerProgramme->setShortcut(QKeySequence("Ctrl+S"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionEnregistrerProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionSupprmierProjet = new QAction(QIcon::fromTheme("edit-delete"), "Supprimer le Projet", this);
        menuFichier->addAction(actionSupprmierProjet);
        actionSupprmierProjet->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionSupprmierProjet, SLOT(setEnabled(bool)));

        QAction *actionSupprmierProgramme = new QAction(QIcon::fromTheme("edit-delete"), "Supprimer le Programme", this);
        menuFichier->addAction(actionSupprmierProgramme);
        actionSupprmierProgramme->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionSupprmierProgramme, SLOT(setEnabled(bool)));

        menuFichier->addSeparator();

        QAction *actionOuvrirProjet = new QAction(QIcon::fromTheme("document-open"), "&Ouvrir un projet", this);
        menuFichier->addAction(actionOuvrirProjet);
        actionOuvrirProjet->setShortcut(QKeySequence("Ctrl+Shift+O"));

        QAction *actionOuvrirProgramme = new QAction(QIcon::fromTheme("document-open"), "O&uvrir un programme", this);
        menuFichier->addAction(actionOuvrirProgramme);
        actionOuvrirProgramme->setDisabled(true);
        actionOuvrirProgramme->setShortcut(QKeySequence("Ctrl+O"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOuvrirProgramme, SLOT(setEnabled(bool)));

        QMenu *sous_menuProjetsRecents = new QMenu("Fichiers &Récents");
        menuFichier->addMenu(sous_menuProjetsRecents);

        menuFichier->addSeparator();
        QAction *actionQuitter = new QAction(QIcon::fromTheme("application-exit"), "&Quitter", this);
        menuFichier->addAction(actionQuitter);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));


    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        QAction *actionAnnuler = new QAction(QIcon::fromTheme("edit-undo"), "&Annuler", this);
        menuEdition->addAction(actionAnnuler);
        actionAnnuler->setDisabled(true);
        actionAnnuler->setShortcut(QKeySequence("Ctrl+Z"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionAnnuler, SLOT(setEnabled(bool)));

        QAction *actionRefaire = new QAction(QIcon::fromTheme("edit-redo"), "&Refaire", this);
        menuEdition->addAction(actionRefaire);
        actionRefaire->setDisabled(true);
        actionRefaire->setShortcut(QKeySequence("Ctrl+Shift+Z"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRefaire, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionCouper = new QAction(QIcon::fromTheme("edit-cut"), "Co&uper", this);
        menuEdition->addAction(actionCouper);
        actionCouper->setDisabled(true);
        actionCouper->setShortcut(QKeySequence("Ctrl+X"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionCouper, SLOT(setEnabled(bool)));

        QAction *actionCopier = new QAction(QIcon::fromTheme("edit-copy"), "Cop&ier", this);
        menuEdition->addAction(actionCopier);
        actionCopier->setDisabled(true);
        actionCopier->setShortcut(QKeySequence("Ctrl+C"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionCopier, SLOT(setEnabled(bool)));

        QAction *actionColler = new QAction(QIcon::fromTheme("edit-paste"), "C&oller", this);
        menuEdition->addAction(actionColler);
        actionColler->setDisabled(true);
        actionColler->setShortcut(QKeySequence("Ctrl+V"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionColler, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionToutSelectionner = new QAction(QIcon::fromTheme("edit-select-all"), "Tout &sélectionner", this);
        menuEdition->addAction(actionToutSelectionner);
        actionToutSelectionner->setDisabled(true);
        actionToutSelectionner->setShortcut(QKeySequence("Ctrl+A"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionToutSelectionner, SLOT(setEnabled(bool)));

        menuEdition->addSeparator();

        QAction *actionRechercher = new QAction(QIcon::fromTheme("edit-find"), "&Rechercher", this);
        menuEdition->addAction(actionRechercher);
        actionRechercher->setDisabled(true);
        actionRechercher->setShortcut(QKeySequence("Ctrl+F"));
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRechercher, SLOT(setEnabled(bool)));

        QAction *actionRechercherRemplacer = new QAction(QIcon::fromTheme("edit-find-replace"), "Rechercher et Remplacer", this);
        menuEdition->addAction(actionRechercherRemplacer);
        actionRechercherRemplacer->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionRechercherRemplacer, SLOT(setEnabled(bool)));

    QMenu *menuInsertion = menuBar()->addMenu("&Insertion");
        QMenu *menuInsertionCOM = menuInsertion->addMenu("&Boucles et Structures Conditionnelles");
            QAction *actionInsertionStructureIf = new QAction("Structure conditionnelle If", this);
            menuInsertionCOM->addAction(actionInsertionStructureIf);
            connect(actionInsertionStructureIf, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionIf = new QAction("&If", this);
            menuInsertionCOM->addAction(actionInsertionIf);
            connect(actionInsertionIf, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionThen = new QAction("&Then", this);
            menuInsertionCOM->addAction(actionInsertionThen);
            connect(actionInsertionThen, SIGNAL(triggered()), this, SLOT(insertionTexte()));


            QAction *actionInsertionElse = new QAction("&Else", this);
            menuInsertionCOM->addAction(actionInsertionElse);
            connect(actionInsertionElse, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionIfEnd = new QAction("I&fEnd", this);
            menuInsertionCOM->addAction(actionInsertionIfEnd);
            connect(actionInsertionIfEnd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleWhile = new QAction("Boucle While", this);
            menuInsertionCOM->addAction(actionInsertionBoucleWhile);
            connect(actionInsertionBoucleWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionWhile = new QAction("&While", this);
            menuInsertionCOM->addAction(actionInsertionWhile);
            connect(actionInsertionWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionWhileEnd = new QAction("WhileE&nd", this);
            menuInsertionCOM->addAction(actionInsertionWhileEnd);
            connect(actionInsertionWhileEnd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleDoLpWhile = new QAction("Boucle Do LpWhile", this);
            menuInsertionCOM->addAction(actionInsertionBoucleDoLpWhile);
            connect(actionInsertionBoucleDoLpWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionDo = new QAction("&Do", this);
            menuInsertionCOM->addAction(actionInsertionDo);
            connect(actionInsertionDo, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionLpWhile = new QAction("&LpWhile", this);
            menuInsertionCOM->addAction(actionInsertionLpWhile);
            connect(actionInsertionLpWhile, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionCOM->addSeparator();

            QAction *actionInsertionBoucleFor = new QAction("Boucle For", this);
            menuInsertionCOM->addAction(actionInsertionBoucleFor);
            connect(actionInsertionBoucleFor, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionFor = new QAction("&For", this);
            menuInsertionCOM->addAction(actionInsertionFor);
            connect(actionInsertionFor, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTo = new QAction("T&o", this);
            menuInsertionCOM->addAction(actionInsertionTo);
            connect(actionInsertionTo, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionStep = new QAction("&Step", this);
            menuInsertionCOM->addAction(actionInsertionStep);
            connect(actionInsertionStep, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionNext = new QAction("Ne&xt", this);
            menuInsertionCOM->addAction(actionInsertionNext);
            connect(actionInsertionNext, SIGNAL(triggered()), this, SLOT(insertionTexte()));

        QMenu *menuInsertionListMat = menuInsertion->addMenu("&Listes et Matrices");
            QAction *actionInsertionList = new QAction("&List", this);
            menuInsertionListMat->addAction(actionInsertionList);
            connect(actionInsertionList, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionListVersMat = new QAction("List -> Mat", this);
            menuInsertionListMat->addAction(actionInsertionListVersMat);
            connect(actionInsertionListVersMat, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListGeneration = menuInsertionListMat->addMenu("Générations de Listes");
                QAction *actionInsertionDim = new QAction("Dim", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionDim);
                connect(actionInsertionDim, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionFill = new QAction("Fill", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionFill);
                connect(actionInsertionFill, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSeq = new QAction("Seq", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionSeq);
                connect(actionInsertionSeq, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionAugment = new QAction("Augment", this);
                menuInsertionListMatListGeneration->addAction(actionInsertionAugment);
                connect(actionInsertionAugment, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListSelection = menuInsertionListMat->addMenu("Sélection d'élements sur les Listes");
                QAction *actionInsertionMin = new QAction("Min", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMin);
                connect(actionInsertionMin, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionMax = new QAction("Max", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMax);
                connect(actionInsertionMax, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionMedian = new QAction("Median", this);
                menuInsertionListMatListSelection->addAction(actionInsertionMedian);
                connect(actionInsertionMedian, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListModifications = menuInsertionListMat->addMenu("Modifications sur les Listes");
                QAction *actionInsertionSortA = new QAction("SortA", this);
                menuInsertionListMatListModifications->addAction(actionInsertionSortA);
                connect(actionInsertionSortA, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSortD = new QAction("SortD", this);
                menuInsertionListMatListModifications->addAction(actionInsertionSortD);
                connect(actionInsertionSortD, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatListCalculs = menuInsertionListMat->addMenu("Calculs sur les Listes");
                QAction *actionInsertionMean = new QAction("Mean", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionMean);
                connect(actionInsertionMean, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionSum = new QAction("Sum", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionSum);
                connect(actionInsertionSum, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionProd = new QAction("Prod", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionProd);
                connect(actionInsertionProd, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionCuml = new QAction("Cuml", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionCuml);
                connect(actionInsertionCuml, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionPercent = new QAction("Percent", this);
                menuInsertionListMatListCalculs->addAction(actionInsertionPercent);
                connect(actionInsertionPercent, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            menuInsertionListMat->addSeparator();

            QAction *actionInsertionMat = new QAction("&Mat", this);
            menuInsertionListMat->addAction(actionInsertionMat);
            connect(actionInsertionMat, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionMatVersList = new QAction("&Mat -> List", this);
            menuInsertionListMat->addAction(actionInsertionMatVersList);
            connect(actionInsertionMatVersList, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QMenu *menuInsertionListMatMatGeneration = menuInsertionListMat->addMenu("Génération de Matrices");
                menuInsertionListMatMatGeneration->addAction(actionInsertionDim);
                menuInsertionListMatMatGeneration->addAction(actionInsertionFill);

            QMenu *menuInsertionListMatMatCalculs = menuInsertionListMat->addMenu("Calculs sur les matrices");
                QAction *actionInsertionDet = new QAction("Det", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionDet);
                connect(actionInsertionDet, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionTrn = new QAction("Trn", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionTrn);
                connect(actionInsertionTrn, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                menuInsertionListMatMatCalculs->addAction(actionInsertionAugment);

                QAction *actionInsertionIden = new QAction("Identity", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionIden);
                connect(actionInsertionIden, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionRef = new QAction("Ref", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionRef);
                connect(actionInsertionRef, SIGNAL(triggered()), this, SLOT(insertionTexte()));

                QAction *actionInsertionRref = new QAction("Rref", this);
                menuInsertionListMatMatCalculs->addAction(actionInsertionRref);
                connect(actionInsertionRref, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionSwap = new QAction("Swap", this);
            menuInsertionListMat->addAction(actionInsertionSwap);
            connect(actionInsertionSwap, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTimesRow = new QAction("*Row", this);
            menuInsertionListMat->addAction(actionInsertionTimesRow);
            connect(actionInsertionTimesRow, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionTimesRowPlus = new QAction("*Row+", this);
            menuInsertionListMat->addAction(actionInsertionTimesRowPlus);
            connect(actionInsertionTimesRowPlus, SIGNAL(triggered()), this, SLOT(insertionTexte()));

            QAction *actionInsertionRowPlus = new QAction("Row+", this);
            menuInsertionListMat->addAction(actionInsertionRowPlus);
            connect(actionInsertionRowPlus, SIGNAL(triggered()), this, SLOT(insertionTexte()));

    menuInsertion->setDisabled(true);
    connect(this, SIGNAL(activerMenusProjet(bool)), menuInsertion, SLOT(setEnabled(bool)));

    QMenu *menuOutils = menuBar()->addMenu("&Outils");
        QAction *actionVueOnglet = new QAction("Vue en onglets", this);
        menuOutils->addAction(actionVueOnglet);
        actionVueOnglet->setCheckable(true);
        actionVueOnglet->setChecked(true);

        menuOutils->addSeparator();

        QAction *actionOptionsProjet = new QAction("Options du Projet", this);
        menuOutils->addAction(actionOptionsProjet);
        actionOptionsProjet->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOptionsProjet, SLOT(setEnabled(bool)));


        QAction *actionOptionsProgramme = new QAction("Options du programme", this);
        menuOutils->addAction(actionOptionsProgramme);
        actionOptionsProgramme->setDisabled(true);
        connect(this, SIGNAL(activerMenusProjet(bool)), actionOptionsProgramme, SLOT(setEnabled(bool)));

        menuOutils->addSeparator();

        QAction *actionFenetrePreferences = new QAction(QIcon::fromTheme("preferences-other"), "&Préférences...", this);
        menuOutils->addAction(actionFenetrePreferences);

    QMenu *menuAide = menuBar()->addMenu("&Aide");
        QAction *actionAideSommaire = new QAction("Sommaire...", this);
        menuAide->addAction(actionAideSommaire);
        actionAideSommaire->setShortcut(QKeySequence("F1"));

        menuAide->addSeparator();

        QAction *actionAPropos = new QAction("À Propos", this);
        menuAide->addAction(actionAPropos);

        QAction *actionAProposQt = new QAction("À Propos de Qt", this);
        menuAide->addAction(actionAProposQt);

    // ==============
    // == FIN MENU ==
    // ==============

    // =============
    // == TOOLBAR ==
    // =============

    QToolBar *toolBarMain = addToolBar("Fichier");
    toolBarMain->addAction(actionQuitter);
    toolBarMain->addAction(actionNouveauProgramme);
    toolBarMain->addAction(actionEnregistrerProgramme);
    toolBarMain->addAction(actionOuvrirProgramme);
    toolBarMain->addAction(actionFermerProgramme);
    toolBarMain->addSeparator();
    toolBarMain->addAction(actionFenetrePreferences);


    // =================
    // == FIN TOOLBAR ==
    // =================

    // =================
    // == DOCK WIDGET ==
    // =================

    treeView = new QTreeWidget;
    treeView->setColumnCount(2);
    QStringList *treeViewHeaders = new QStringList(QString("Nom"));
    treeViewHeaders->append(QString("Taille"));
    treeView->setHeaderLabels(*treeViewHeaders);

    QDockWidget *dockWidget = new QDockWidget("Gestionnaire de Projet", this);
    dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget->setWidget(treeView);
    dockWidget->setMinimumWidth(175);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
connect(this, SIGNAL(activerMenusProjet(bool)), actionNouveauProgramme, SLOT(setEnabled(bool)));
    // =====================
    // == FIN DOCK WIDGET ==
    // =====================

    // =============
    // == FENETRE ==
    // =============

    // Rien à déclarer

    // =================
    // == FIN FENETRE ==
    // =================

    connect(treeView, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(treeWidgetItemDoubleClicked(QTreeWidgetItem*,int)));

    connect(actionNouveauProjet, SIGNAL(triggered()), this,SLOT(nouveauProjet()));
    connect(actionNouveauProgramme, SIGNAL(triggered()), this, SLOT(nouveauProgramme()));

    connect(actionFermerProjet, SIGNAL(triggered()), this, SLOT(fermerProjet()));
    connect(actionFermerProgramme, SIGNAL(triggered()), this, SLOT(fermerProgramme()));

    connect(actionEnregistrerProjet, SIGNAL(triggered()), this, SLOT(enregistrerProjet()));
    connect(actionEnregistrerProgramme, SIGNAL(triggered()), this, SLOT(enregistrerProgramme()));

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(actionVueOnglet, SIGNAL(toggled(bool)), this, SLOT(changerVueOnglet(bool)));

    connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    zoneCentrale->setViewMode(QMdiArea::TabbedView);

    setCentralWidget(zoneCentrale);

    this->setWindowTitle("Cat Editor");

    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{

}

void MainWindow::treeWidgetItemDoubleClicked(QTreeWidgetItem* treeWidgetItemClicked, int columnClicked)
{
    bool trouve(false);
    QList<QMdiSubWindow*>::Iterator it;
    // Itération sur la liste des subWindow de la MdiArea
    for (it = zoneCentrale->subWindowList().begin(); it != zoneCentrale->subWindowList().end(); ++it) {
        if ((*it)->windowTitle() == treeWidgetItemClicked->text(0)) { // Si Le titre de la fenetre est le meme que celui du treeWidgetItemClicked
            zoneCentrale->setActiveSubWindow(*it);
            trouve = true;
            break;
        }
    }

    if (!trouve) {
        QTextEdit *zoneTexte = new QTextEdit;
        QMdiSubWindow *subWindow = zoneCentrale->addSubWindow(zoneTexte, Qt::CustomizeWindowHint); // Qt::CustomizeWindowHint pour pouvoir redéfinir les raccourcis prédéfinis par QT
        subWindow->setWindowTitle(treeWidgetItemClicked->text(0));
        subWindow->show();
    }

}

QString MainWindow::catParser(const QString &contenu) const
{
    QString texteEnregistrement("");

    QStringList lignesTexte = contenu.split("\n"); // Traitement du texte par lignes

    foreach (QString ligne, lignesTexte) {
        foreach (const QString &pattern, keywordPatterns) {
            QRegExp expression(pattern);
            int index = expression.indexIn(ligne);

            while (index >= 0) {
                int length = expression.matchedLength();
                ligne.insert(index, QString("\\"));
                index = expression.indexIn(ligne, index + length);
            }
        }
        texteEnregistrement.append(ligne + "\n");
    }
    texteEnregistrement.remove(texteEnregistrement.length() - 1, 1); // Enleve le dernier retour à la ligne ajouté

    return texteEnregistrement;
}

QString MainWindow::genCatFile(const QMap<QString, Programme> &programmes) const
{
    QString catFile;
    foreach (Programme programmeEnCours, programmes) {
        QString contenuCatFile = catParser(programmeEnCours.contenu);
        int capacity = countCatFile(contenuCatFile);

        catFile += "%Header Record\n";
        catFile += "Format:TXT\n";
        catFile += "Communication SW:0\n";
        catFile += "Data Type:PG\n";
        catFile += "Capacity:" + (QString)capacity + "\n";
        catFile += "File Name:" + programmeEnCours.nomPourCalculatrice + "\n";
        catFile += "Group Name:\n";
        catFile += "Password:" + programmeEnCours.motDePasse + "\n";
        catFile += "Option1:NL\n";
        catFile += "Option2:\n";
        catFile += "Option3:\n";
        catFile += "%Data Record\n";
        catFile += contenuCatFile + "\n";
        catFile += "%End";
    }

    return catFile;
}

QString MainWindow::convToRawFormat(const QString &contenu) const
{
    QString rawText();

}

int MainWindow::countCatFile(const QString &contenuCatFile) const
{
    int count(0);
    for (int i = 0; i < contenuCatFile.length(); ++i) {
        if (contenuCatFile[i] == '\\') {
            //Count la commande en format RAW
        }
        else {
            count++;
        }
    }

    return count;
}

QDomDocument MainWindow::genFichierProjet(const Projet &projet) const
{
    /*
     * QDomImplementation imp = QDomDocument().implementation();
     * QDomDocument document(imp.createDocumentType(projetEnCours.name, QString("publicId"), QString("systemId")));
     */
    QDomDocument document(projet.name);
    QDomElement domElementProject = document.createElement("project");

    QDomElement domElementProjectName = document.createElement("name");
    domElementProjectName.appendChild(document.createTextNode(projet.name));
    domElementProject.appendChild(domElementProjectName);

    QDomElement domElementPrograms = document.createElement("programs");
    foreach(const Programme &programmeEnCours, projet.programmes) {
        QDomElement domElementCurrentProgram = document.createElement("program");

        QDomElement domElementProgramName = document.createElement("name");
        domElementProgramName.appendChild(document.createTextNode(programmeEnCours.name));
        domElementCurrentProgram.appendChild(domElementProgramName);

        QDomElement domElementCalculatorProgramName = document.createElement("calculator_name");
        domElementCalculatorProgramName.appendChild(document.createTextNode(programmeEnCours.nomPourCalculatrice));
        domElementCurrentProgram.appendChild(domElementCalculatorProgramName);

        domElementPrograms.appendChild(domElementCurrentProgram);
    }

    domElementProject.appendChild(domElementPrograms);

    document.appendChild(domElementProject);

    return document;
}

void MainWindow::ecrireProgramme(QString nomFichier, const QString &contenu) const
{
    QFile fichier(nomFichier);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error("Impossible d'ouvrir / écrire dans le fichier. Vérifier l'emplacement de celui-ci.");
        return;
    }

    QTextStream fluxFichierProgramme(&fichier);
    fluxFichierProgramme << contenu;
}

QWidget* MainWindow::nouvelleFenetre(QString const& contenu) const
{
    QTextEdit *editeurTexte = new QTextEdit(contenu);
    editeurTexte->setFont(QFont("Monospace"));
    editeurTexte->setStyleSheet("background-color:white;");
    MyHighlighter *highlighter = new MyHighlighter(editeurTexte->document());
    return editeurTexte;
}

QString MainWindow::clearInsertText(QString texte) const
{
    texte.remove("&");

    if (texte == "Structure conditionnelle If")
        return "If I>=42\nThen \nElse \nIfEnd";

    else if (texte == "Boucle While")
        return "While I>=42\n\nWhileEnd";

    else if (texte == "Boucle Do LpWhile")
        return "Do\n\nLpWhile I>=42";

    else if (texte == "Boucle For")
        return "For 1->I To 42 Step 1\n\nNext";

    else if (texte == "List -> Mat")
        return "List->Mat(";

    else if (texte == "Mat -> List")
        return "Mat->List(";

    else if (texte == "To" || texte == "Step")
        return texte.append(" ").prepend(" ");

    else if (texte == "IfEnd" || texte == "WhileEnd" || texte == "Do" || texte == "Next")
        return texte;

    else if (texte == "If" || texte == "Then" || texte == "Else" || texte == "While" || texte == "LpWhile" || texte == "For"
             || texte == "List" || texte == "Dim" || texte == "Sum" || texte == "Prod" || texte == "Cuml" || texte == "Percent"
             || texte == "Mat" || texte == "Det" || texte == "Trn" || texte == "Identity" || texte == "Ref" || texte == "Rref" || texte == "Swap" || texte == "*Row" || texte == "*Row+" || texte == "Row+")
        return texte.append(" ");

    else if (texte == "Fill" || texte == "Seq" || texte == "Augment" || texte == "Min" || texte == "Max" || texte == "Median" || texte == "SortA" || texte == "SortD" || texte == "Mean")
        return texte.append("(");

    else
        return texte;
}

void MainWindow::nouveauProjet()
{
    bool okProjet = false;
    QString nomProjet = QInputDialog::getText(this, "Nouveau Projet", "Quel est le nom de votre projet ?", QLineEdit::Normal, QString(), &okProjet);

    if (okProjet && !nomProjet.isEmpty()) {
        bool ok = false;
        QString nomProgramme = QInputDialog::getText(this, "Nouveau Projet", "Quel est le nom de votre premier programme ?", QLineEdit::Normal, QString(), &ok);

        if (ok && !nomProgramme.isEmpty()) {
            zoneCentrale->closeAllSubWindows();
            QMdiSubWindow *newSubWindow = zoneCentrale->addSubWindow(nouvelleFenetre(), Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint); // Qt::CustomizeWindowHint pour pouvoir redéfinir les raccourcis prédéfinis par QT
            newSubWindow->setWindowTitle(nomProgramme);
            newSubWindow->show();

            QStringList *nouveauProgrammeHeader = new  QStringList(QString(nomProgramme));
            nouveauProgrammeHeader->append(QString("Non enregistré"));
            QTreeWidgetItem *treeWidgetNewItem = new QTreeWidgetItem(*nouveauProgrammeHeader);
            treeView->insertTopLevelItem(0, treeWidgetNewItem);

            Programme nouvProgramme;
            nouvProgramme.name = nomProgramme;

            emit activerMenusProjet(true);
            projetEnCours.name = nomProjet;
            projetEnCours.programmes.insert(nomProgramme, nouvProgramme);
            projetEnCours.dir = QDir();
        }
    }
}

void MainWindow::nouveauProgramme()
{
    bool ok = false;
    QString nomProgramme = QInputDialog::getText(this, "Nouveau Programme", "Quel est le nom de votre nouveau programme ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !nomProgramme.isEmpty()) {
        QMdiSubWindow *subWindow = zoneCentrale->addSubWindow(nouvelleFenetre(), Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint);
        subWindow->setWindowTitle(nomProgramme);
        subWindow->show();

        QStringList *nouveauProgrammeHeader = new QStringList(QString(nomProgramme));
        nouveauProgrammeHeader->append(QString("Non enregistré"));
        QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(*nouveauProgrammeHeader);
        treeView->insertTopLevelItem(treeView->topLevelItemCount(), treeWidgetItem);

        Programme nouvProgramme;
        nouvProgramme.name = nomProgramme;

        projetEnCours.programmes.insert(nomProgramme, nouvProgramme);
    }
}

void MainWindow::fermerProjet()
{
    zoneCentrale->closeAllSubWindows();

    for (int i = treeView->topLevelItemCount()-1; i >= 0; --i) {
        treeView->takeTopLevelItem(i);
    }

    emit activerMenusProjet(false);
}

void MainWindow::fermerProgramme()
{
    zoneCentrale->closeActiveSubWindow();
}

void MainWindow::enregistrerProjet()
{
    if(projetEnCours.dir.path() == ".") {
        QString stringDirProjet = QFileDialog::getExistingDirectory(this, "Enregistrer le Projet");
        QDir dirProjet(stringDirProjet);

        if(dirProjet.exists() && dirProjet.path() != ".") {
            projetEnCours.dir = dirProjet;
        } else {
            return;
        }
    }

    QList<QMdiSubWindow*> programmesAEnregistrer = zoneCentrale->subWindowList();

    foreach (QMdiSubWindow* programme, programmesAEnregistrer) {
        QString texteAEnregistrer = catParser(((QTextEdit*)programme->widget())->toPlainText());
        projetEnCours.programmes[((QTextEdit*)programme->widget())->windowTitle()].contenu = texteAEnregistrer;

        /*
        try {
            ecrireProgramme(projetEnCours.fichierProgramme[programme->windowTitle()], texteAEnregistrer);
        } catch (std::exception const& e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
        */
    }

    QString contenuCatFile = genCatFile(projetEnCours.programmes);

    QDomDocument domDocumentProjet = genFichierProjet(projetEnCours);

    try {
        ecrireProgramme(projetEnCours.dir.path() + "/project.cated", domDocumentProjet.toString());
    } catch (std::exception const& e) {
            QMessageBox::critical(this, "Erreur", e.what());
    }
}

void MainWindow::enregistrerProgramme()
{
    QString nomProgramme = zoneCentrale->activeSubWindow()->windowTitle();
    QTextEdit *zoneTexteProgramme = (QTextEdit*)zoneCentrale->activeSubWindow()->widget();

    if (projetEnCours.dir.path() == ".") {
        QString stringDirProjet = QFileDialog::getExistingDirectory(this, "Enregistrer le Projet");
        QDir dirProjet(stringDirProjet);

        if(dirProjet.exists() && dirProjet.path() != ".") {
            projetEnCours.dir = dirProjet;
        } else {
            return;
        }
    }

    QString texteEnregistrement = catParser(zoneTexteProgramme->toPlainText());
    projetEnCours.programmes[nomProgramme].contenu = texteEnregistrement;

    /*
    try {
        ecrireProgramme(projetEnCours.fichierProgramme[nomProgramme], texteEnregistrement);
    } catch (std::exception const& e) {
        QMessageBox::critical(this, "Erreur", e.what());
    }
    */
}

void MainWindow::supprimerProgramme()
{
    QString nomProgramme = zoneCentrale->currentSubWindow()->windowTitle();
    for (int i = 0; i < treeView->topLevelItemCount(); ++i) {
        if(treeView->topLevelItem(i)->text(0) == nomProgramme) {
            treeView->takeTopLevelItem(i);
            break;
        }
    }

    projetEnCours.programmes.remove(nomProgramme);

    zoneCentrale->closeActiveSubWindow();
}

void MainWindow::insertionTexte()
{
    QAction *actionSender = (QAction*)sender(); // Action ayant envoyé le signal
    // Le qobject_cast<QTextEdit*> convertit le QWidget* retourné par ->widget() en QTextEdit*
    qobject_cast<QTextEdit*>(zoneCentrale->currentSubWindow()->widget())->insertPlainText(clearInsertText(actionSender->text()));
}

void MainWindow::changerVueOnglet(bool vueOnglet)
{
    if(vueOnglet)
        zoneCentrale->setViewMode(QMdiArea::TabbedView);
    else
        zoneCentrale->setViewMode(QMdiArea::SubWindowView);
}
