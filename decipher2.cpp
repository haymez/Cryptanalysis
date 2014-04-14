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
	char cipher[] = "Tsj tk ymj ymnslx Ktwi Uwjkjhy mfi fqbfdx ktzsi mfwijxy yt zsijwxyfsi fgtzy mzrfsx bfx ymjnw mfgny tk htsynszfqqd xyfynsl fsi wjujfynsl ymj ajwd ajwd tgantzx, fx ns Ny'x f snhj ifd, tw Dtz'wj ajwd yfqq, tw Tm ijfw dtz xjjr yt mfaj kfqqjs itbs f ymnwyd-ktty bjqq, fwj dtz fqwnlmy? Fy knwxy Ktwi mfi ktwrji f ymjtwd yt fhhtzsy ktw ymnx xywfslj gjmfantzw. Nk mzrfs gjnslx its'y pjju jcjwhnxnsl ymjnw qnux, mj ymtzlmy, ymjnw rtzymx uwtgfgqd xjnej zu. Fkyjw f kjb rtsymx' htsxnijwfynts fsi tgxjwafynts mj fgfsitsji ymnx ymjtwd ns kfatzw tk f sjb tsj. Nk ymjd its'y pjju ts jcjwhnxnsl ymjnw qnux, mj ymtzlmy, ymjnw gwfnsx xyfwy btwpnsl. Fkyjw f bmnqj mj fgfsitsji ymnx tsj fx bjqq fx gjnsl tgxywzhynajqd hdsnhfq.";
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
