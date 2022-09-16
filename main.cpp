#include "my_lib.hpp"

struct irasas {
string vardas;
string pavarde;
int paz[10];
int egzas;
double galut;
double galut2;
float median;
};

int main() {
  irasas temp;
  vector<int> x;
  int n = 0, sum = 0;
  int t;
  
  cout<<"Iveskite varda: "; cin>>temp.vardas;
  cout<<"Iveskite pavarde: "; cin>>temp.pavarde;
  cout <<"Iveskite egzamino paz.: "; cin>>temp.egzas;
  /*cout <<"Kiek turi paz. (1-10)? "; cin>>n;*/

 /* for (int i = 0; i < n; i++){
    cout<<"Iveskite "<<i+1<<"-aji paz.";
    cin>>temp.paz[i];
    sum+=temp.paz[i];
    }*/

  cout<<std::endl<<std::endl;
  cout << "Suvedus reikiamus pazymius - iveskite endl"<<endl;
  cout<<std::endl<<std::endl;
  cout<<"Iveskite "<< n+1<<" -aji paz. ";
    while ( cin>>temp.paz[n])
   {
     if (isdigit(temp.paz[n]) == false ){
      cout<<"Iveskite "<<n+2<<" -aji paz. ";
       x.push_back(temp.paz[n]);
      sum +=temp.paz[n];
      n +=1;}
     else
       cout<< " Pazymys ivestas    "<<endl;
  }


for (int i = 0; i < n; i++){
  for (int j = 0; j < n - i - 1; j++)
			if (temp.paz[j] < temp.paz[j + 1])
			{
				t = temp.paz[j];
				temp.paz[j] = temp.paz[j + 1];
				temp.paz[j + 1] = t;
			}
  if (n%2 == 0) // if SIZE is even 
	{temp.median = (temp.paz[n/2] + temp.paz[n/2-1])/2.0;}
	else
    temp.median = temp.paz[n/2];
    }

  temp.galut = double(sum) / double(n)*0.4 + temp.egzas*0.6;
  temp.galut2 = temp.median*0.4 + temp.egzas*0.6;

cout 
  << setw(10)
  << left 
  << "Vardas"
  << setw(10)
  << left 
  << "Pavarde"
  << setw(19) 
  << left 
  << "Galutinis (Vid.) / "
  << setw(10)
  << left
  << "Galutinis (Med.) \n"
  << "-----------------------------------------------------"
  << endl;

  {cout << fixed << setprecision(2)
    << left
    << setw(10)
    << temp.vardas
    << left
    << setw(10)
    << temp.pavarde
    << left
    << setw(19)
    << temp.galut
    << left
    << setw(10)
    << temp.galut2;}
  cout << "\n\n";
    
 /*cout << "Vektorius 'v' :";
  for(int e : x){
    cout <<e<<endl;}*/
}
