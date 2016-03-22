#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;
main(){
	char line[100];
	int i,j;
	float a[100],b[100],lab2BMI;
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
		lab2BMI=BMI(a[j],b[j]);
		fout<<fixed<<setprecision(2)<<lab2BMI<<" ";
		if(lab2BMI<15)fout<<"Very severely underweight"<<endl;
		else if(lab2BMI>=15&&lab2BMI<16)fout<<"Severely underweight"<<endl;
		else if(lab2BMI>=16&&lab2BMI<18.5)fout<<"Underweight"<<endl;
		else if(lab2BMI>=18.5&&lab2BMI<25)fout<<"normal"<<endl;
		else if(lab2BMI>=25&&lab2BMI<30)fout<<"Overweight"<<endl;
		else if(lab2BMI>=30&&lab2BMI<35)fout<<"Obese Class I (Moderately obese)"<<endl;
		else if(lab2BMI>=35&&lab2BMI<40)fout<<"Obese Class II (Severely obese)"<<endl;
		else if(lab2BMI>=40)fout<<"Obese Class III (Very severely obese)"<<endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
