#include "coada_cu_proritati.h"
#include "Coada_dubla.h"
using namespace std;

int main()
{
Coada_cu_prioritati<int> codita;

cin>>codita;
codita.reverse();
for(coada<int>::iterator it=codita.begin();it!=++codita.end();it++)cout<<*it<<' ';

    return 0;
}
