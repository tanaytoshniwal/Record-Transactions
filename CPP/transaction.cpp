#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
string currdate="";
namespace cur
{
    template < typename T > string to_string( const T& n )
    {
        ostringstream st ;
        st << n ;
        return st.str() ;
    }
}
string getDate(){
	time_t t=time(0);
    struct tm * now = localtime( & t );
    string date=cur::to_string(now->tm_mday) +"-"+ cur::to_string(now->tm_mon+1)+"-"+cur::to_string(now->tm_year+1900);
    return date;
}
int main(int argc, char *argv[]){
	currdate=getDate();
	ofstream file("transactions.txt",fstream::app);
	file<<currdate<<":"<<endl;
	int n=1;
	do{
		cout<<"Input Transactions?\n1:Yes\n2:No\n";
		try{
			cin>>n;
			if(cin.fail())
				throw "wrong input nigga!";
			if(n==2){
				cout<<"bbye";
				break;
			}
		}catch(const char* msg){
			cout<<msg;
		}
		cout<<"Input Transactions(in a single line):\n";
		string str;
		cin.clear();
		cin.sync();
		getline(cin ,str);
		file<<"\t"<<str<<endl;
	}while(n==1);
	file.close();
	return 0;
}
