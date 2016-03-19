//Author-Rasheed Andrews
//Used to fixed sound problem on my laptop

#include<iostream>
#include<Windows.h>
#include<WinSvc.h>

using namespace std;

int main(){

	cout << "\t****** Designed by Rasheed Andrews ******   [PLEASE RUN AS ADMIN]\n\n\n";

	

	//Gets Access to Services Database
	SC_HANDLE SCManager=OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
	//Machine Name-NULL......Database Name-NULL.......Access to Rights

	if(SCManager==NULL){
	cout<<"Could not open Service Manager Database"<<endl;
	
	//LIST OF POSSIBLE ERRORS
	cout<<"Reason for Error: ";
	if(GetLastError()==ERROR_ACCESS_DENIED){
	cout<<"Access Denied"<<endl;
	}

	if(GetLastError()==ERROR_DATABASE_DOES_NOT_EXIST)
	cout<<"Database does not exist"<<endl;
    }
	else{
	cout<<"Service Manager Database Successfully opened"<<endl;
	}
	getchar();

	

	//Connecting to Particular Service-Audio
	SC_HANDLE SHandle=OpenService(SCManager,"AudioSrv",SC_MANAGER_ALL_ACCESS);

	if(SHandle==NULL){

	cout<<"Could not Connect to Service"<<endl;
	
	cout<<"Reason for Error: ";
	if(GetLastError()==ERROR_ACCESS_DENIED){
	cout<<"Access Denied"<<endl;
	}

	if(GetLastError()==ERROR_INVALID_NAME){
	cout<<"Invalid Name"<<endl;
	}

	if(GetLastError()==ERROR_SERVICE_DOES_NOT_EXIST){
	cout<<"Service Does Not Exist"<<endl;
	}

	if(GetLastError()==ERROR_INVALID_HANDLE){
	cout<<"Invalid Handle"<<endl;
	}

	}
	else{
	cout<<"Connection to service was successfull"<<endl;
	}

	 

	getchar();



	//Shutting Down the Service
	SERVICE_STATUS_PROCESS Status;

	BOOL C=ControlService(SHandle,SERVICE_CONTROL_STOP,(LPSERVICE_STATUS)&Status);

	
	
	if(C==NULL){
	cout<<"Service was not Stopped"<<endl;

	cout<<"Reason for Error: ";

	//LIST OF POSSIBLE ERRORS
	if(GetLastError()==ERROR_ACCESS_DENIED){
	cout<<"Access Denied"<<endl;
	}

	}
	else{
	cout<<"Service was Successfully Stopped"<<endl;
	}
	getchar();





	//Starting Back Service

	BOOL B=StartService(SHandle,NULL,NULL);

	if(B==NULL){
		cout<<"Service Could not be Started"<<endl;

		cout<<"Reason for Error: ";

		//LIST OF POSSIBLE ERRORS

		if(GetLastError()==ERROR_ACCESS_DENIED){
		cout<<"Access Denied";
		}
	}

	else{
	cout<<"Service Successfully Started"<<endl;
	}
	getchar();

	CloseServiceHandle(SCManager);
    CloseServiceHandle(SHandle);

	cout<<endl<<endl<<"**THANK YOU**";
	getchar();
    
}
