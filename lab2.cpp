#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;
main(){
	char line[100];
	int i,j;
	float a[100],b[100],ans[100];
	fstream fin;
	fstream fout;
	fin.open("file.in.txt",ios::in);
	fout.open("file.out.txt",ios::out);
	for(i=0;;i++){
		fin.getline(line,sizeof(line),' ');
		a[i]=atof(line);
		fin.getline(line,sizeof(line),'\n');
		b[i]=atof(line);
		if(a[i]==0&&b[i]==0)break;
	}
	for(j=0;j<i;j++){
		ans[j]=b[j]/((a[j]/100)*(a[j]/100));
		fout<<fixed<<setprecision(2)<<ans[j]<<" ";
		if(ans[j]<15)fout<<"Very severely underweight"<<endl;
		else if(ans[j]>=15&&ans[j]<16)fout<<"Severely underweight"<<endl;
		else if(ans[j]>=16&&ans[j]<18.5)fout<<"Underweight"<<endl;
		else if(ans[j]>=18.5&&ans[j]<25)fout<<"normal"<<endl;
		else if(ans[j]>=25&&ans[j]<30)fout<<"Overweight"<<endl;
		else if(ans[j]>=30&&ans[j]<35)fout<<"Obese Class I (Moderately obese)"<<endl;
		else if(ans[j]>=35&&ans[j]<40)fout<<"Obese Class II (Severely obese)"<<endl;
		else if(ans[j]>=40)fout<<"Obese Class III (Very severely obese)"<<endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
