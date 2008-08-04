#ifndef edit_retoptoolDIALOG_H
#define edit_retoptoolDIALOG_H



#include <QDockWidget>

#include <QtGui/QApplication>
#include <meshlab/interfaces.h>

#include "ui_edit_retoptooldialog.h"

using namespace std;
using namespace vcg;

typedef enum 
	{
		U_NONE,
		U_VTX_SEL,
		U_VTX_SEL_FREE,
		U_VTX_DEL,
		U_VTX_CONNECT,
		U_VTX_DE_CONNECT,		
		U_FCE_SEL
	} UtensType;


class edit_retoptooldialog : public QDockWidget
{
	Q_OBJECT
		
	public:
		edit_retoptooldialog(QWidget *parent = 0);
		~edit_retoptooldialog();
			
		UtensType utensil;
		void insertVertexInTable(QString c1, QString c2, QString c3, QString c4);
		void removeVertexInTable(QString vName);
		void removeVertexInTable(QString vx, QString vy, QString vz);

		void insertConnectionInTable(QString c1, QString c2);
		void removeConnectionInTable(QString c1, QString c2);

		void insertFaceInTable(QString v1, QString v2, QString v3);
		void removeFaceInTable(QString v1, QString v2, QString v3);

		bool isRadioButtonSimpleChecked();
		bool isCheckBoxTrColorChecked();
		int getIterations();
		int dist(int d);

		void setBarMax(int val);
		void setBarVal(int val);

	private:
		Ui::edit_retoptooldialog ui;
		QWidget* parent;
	
	private slots:

		// 1) Vtx selection
		void on_ButtonSelectVertex_clicked();
		void on_ButtonSelectVertexFree_clicked();
		void on_ButtonDeSelectVertex_clicked();
		// 2) Vtx connection
		void on_ButtonConnectVertex_clicked();
		void on_ButtonDeConnectVertex_clicked();
		// 3) Face selection
		void on_toolBox_currentChanged(int i);

		void on_ButtonSelectFace_clicked();	
		void on_ButtonMeshCreate_clicked();


		// Altro
		void on_ButtonClose_clicked();

	signals:
		void mesh_create();;
		void fuffa();
};

#endif

