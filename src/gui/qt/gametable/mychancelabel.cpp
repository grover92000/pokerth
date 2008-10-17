//
// C++ Implementation: mycardspixmaplabel
//
// Description: 
//
//
// Author: FThauer FHammer <f.thauer@web.de>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "mychancelabel.h"
#include "gametableimpl.h"

using namespace std;

MyChanceLabel::MyChanceLabel(QWidget* parent)
 : QLabel(parent) {

}

MyChanceLabel::~MyChanceLabel()
{
}

void MyChanceLabel::refreshChance(int **chance)
{
	RFChance = chance[9][0];
	SFChance = chance[8][0];
	FOAKChance = chance[7][0];
	FHChance = chance[6][0];
	FLChance = chance[5][0];
	STRChance = chance[4][0];
	TOAKChance = chance[3][0];
	TPChance = chance[2][0];
	OPChance = chance[1][0];
	HCChance = chance[0][0];

	update();
}

void MyChanceLabel::paintEvent(QPaintEvent * event) {

	QPainter painter(this);


#ifdef _WIN32
	QString font1String = "font-family: \"Arial\";";
#else 
	#ifdef __APPLE__	
		QString font1String = "font-family: \"Lucida Grande\";";
	#else 
		QString font1String = "font-family: \"Nimbus Sans L\";";
	#endif
#endif
	QFont font;
	font.setFamily(font1String);
	font.setPixelSize(10);
	painter.setFont(font);

	//Draw Texts
	if(RFChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,0), QPointF(76,13)),Qt::AlignRight,"Royal Flush");
	painter.drawText(QRectF(QPointF(196,0), QPointF(236,13)),Qt::AlignRight,QString("%1%").arg(RFChance));
	if(SFChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,13), QPointF(76,26)),Qt::AlignRight,"Straight Flush");
	painter.drawText(QRectF(QPointF(196,13), QPointF(236,26)),Qt::AlignRight,QString("%1%").arg(SFChance));
	if(FOAKChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,26), QPointF(76,39)),Qt::AlignRight,"Four of a Kind");
	painter.drawText(QRectF(QPointF(196,26), QPointF(236,39)),Qt::AlignRight,QString("%1%").arg(FOAKChance));
	if(FHChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,39), QPointF(76,52)),Qt::AlignRight,"Full House");
	painter.drawText(QRectF(QPointF(196,39), QPointF(236,52)),Qt::AlignRight,QString("%1%").arg(FHChance));
	if(FLChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }	
	painter.drawText(QRectF(QPointF(2,52), QPointF(76,65)),Qt::AlignRight,"Flush");
	painter.drawText(QRectF(QPointF(196,52), QPointF(236,65)),Qt::AlignRight,QString("%1%").arg(FLChance));
	if(STRChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,65), QPointF(76,78)),Qt::AlignRight,"Straight");
	painter.drawText(QRectF(QPointF(196,65), QPointF(236,78)),Qt::AlignRight,QString("%1%").arg(STRChance));
	if(TOAKChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,78), QPointF(76,91)),Qt::AlignRight,"Three of a Kind");
	painter.drawText(QRectF(QPointF(196,78), QPointF(236,91)),Qt::AlignRight,QString("%1%").arg(TOAKChance));
	if(TPChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,91), QPointF(76,104)),Qt::AlignRight,"Two Pairs");
	painter.drawText(QRectF(QPointF(196,91), QPointF(236,104)),Qt::AlignRight,QString("%1%").arg(TPChance));
	if(OPChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,104), QPointF(76,117)),Qt::AlignRight,"One Pair");
	painter.drawText(QRectF(QPointF(196,104), QPointF(236,117)),Qt::AlignRight,QString("%1%").arg(OPChance));
	if(HCChance == 0) { painter.setPen(QColor(85,99,47)); }
	else { painter.setPen(QColor(156,213,0)); }
	painter.drawText(QRectF(QPointF(2,117), QPointF(76,130)),Qt::AlignRight,"Highest Card");
	painter.drawText(QRectF(QPointF(196,117), QPointF(236,130)),Qt::AlignRight,QString("%1%").arg(HCChance));

	//Draw gfx
	painter.setPen(QColor(0,0,0));
	
	QLinearGradient linearGrad(QPointF(80,3), QPointF(190,10));
	linearGrad.setColorAt(0, Qt::blue);
	linearGrad.setColorAt(0.5, Qt::yellow);
	linearGrad.setColorAt(1, Qt::red);
	painter.setBrush(linearGrad);
	
	if(RFChance != 0) painter.drawRect(80,3,(117*RFChance)/100,7);
	if(SFChance != 0) painter.drawRect(80,16,(117*SFChance)/100,7);
	if(FOAKChance != 0) painter.drawRect(80,29,(117*FOAKChance)/100,7);
	if(FHChance != 0) painter.drawRect(80,42,(117*FHChance)/100,7);
	if(FLChance != 0) painter.drawRect(80,55,(117*FLChance)/100,7);
	if(STRChance != 0) painter.drawRect(80,68,(117*STRChance)/100,7);
	if(TOAKChance != 0) painter.drawRect(80,81,(117*TOAKChance)/100,7);
	if(TPChance != 0) painter.drawRect(80,94,(117*TPChance)/100,7);
	if(OPChance != 0) painter.drawRect(80,107,(117*OPChance)/100,7);
	if(HCChance != 0) painter.drawRect(80,120,(117*HCChance)/100,7);
}


void MyChanceLabel::resetChance()
{
	RFChance = 0;
	SFChance = 0;
	FOAKChance = 0;
	FHChance = 0;
	FLChance = 0;
	STRChance = 0;
	TOAKChance = 0;
	TPChance = 0;
	OPChance = 0;
	HCChance = 0;

	update();
}