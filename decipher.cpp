/**
* Input directions:
* 0 to exit program
* 1 to reset cipher
* 2 to undo last change
* 3 to print current working text to a file
* 
* can only undo once
**/


#include<iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
using namespace std;

int main()
{
	char cipher[] = "QHDUOB WHQ BHDUV KDG SDVVHG VLQFH WKH GXUVOHBV KDG ZRNHQ XS WR\n ILQG WKHLU QHSKHZ RQ WKH IURQW VWHS, EXW SULYHW GULYH KDG\n KDUGOB FKDQJHG DW DOO. WKH VXQ URVH RQ WKH VDPH WLGB IURQW JDUGHQV\n DQG OLW XS WKH EUDVV QXPEHU IRXU RQ WKH GXUVOHBV' IURQW GRRU; LW\n FUHSW LQWR WKHLU OLYLQJ URRP, ZKLFK ZDV DOPRVW HADFWOB WKH\n VDPH DV LW KDG EHHQ RQ WKH QLJKW ZKHQ PU. GXUVOHB KDG VHHQ WKDW IDWHIXO QHZV\n UHSRUW DERXW WKH RZOV. RQOB WKH SKRWRJUDSKV RQ WKH PDQWHOSLHFH\n UHDOOB VKRZHG KRZ PXFK WLPH KDG SDVVHG. WHQ BHDUV DJR, WKHUH KDG EHHQ ORWV RI SLFWXUHV\n RI ZKDW ORRNHG OLNH D ODUJH SLQN EHDFK EDOO ZHDULQJ\n GLIIHUHQW-FRORUHG ERQQHWV - EXW GXGOHB GXUVOHB ZDV QR ORQJHU D EDEB, DQG QRZ WKH SKRWRJUDSKV\n VKRZHG D ODUJH EORQG ERB ULGLQJ KLV ILUVW ELFBFOH, RQ D FDURXVHO DW WKH\n IDLU, SODBLQJ D FRPSXWHU JDPH ZLWK KLV IDWKHU, EHLQJ KXJJHG DQG NLVVHG EB KLV PRWKHU. WKH\n URRP KHOG QR VLJQ DW DOO WKDW DQRWKHU ERB OLYHG LQ WKH KRXVH, WRR";
	char manip[1000];
	char undo[1000];
	strncpy(manip, cipher, sizeof(cipher));
	strncpy(undo, cipher, sizeof(cipher));
	
	char current;
	char change;
	while(1)
	{
		//get current command
		cout<<endl<<"---------------------------------------"<<endl<<endl<<manip;
		cout<<endl<<endl<<"What letter to change?"<<endl;
		cin>>current;
		
		//exit on 0
		if(current =='0')
			break;
		
		//reset on one
		if(current == '1')
			strncpy(manip, cipher, sizeof(cipher));
			else if (current == '2')
				strncpy(manip, undo, sizeof(cipher));
			else if (current == '3')
				{
					ofstream myfile;
					myfile.open ("CIPHERPRINT.txt");
					myfile << manip;
					myfile.close();
					exit(0);
				}
		else { 
			strncpy(undo, manip, sizeof(cipher));
			cout<<"Change to what?"<<endl;
			cin>>change;
		
			change = tolower(change);
			
			
			//change letters
			for(int i=0; i<sizeof(manip); i++)
			{
				if(manip[i] == current)
				{
					manip[i] = change;
				}
			}
		}
		
	}	

	return 0;
}
