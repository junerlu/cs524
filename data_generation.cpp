#include<bits/stdc++.h>
#include<random>
using namespace std;
int main()
{
	random_device rd;
    mt19937 gen(rd());
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 101; i <= 300; ++i)
	{

		string filename = to_string(i)+".in";
		ofstream fout(filename);
		int exp = i*2;
    	int ins = i*3;
    	uniform_int_distribution<long long> pay_range(1, 300);   // sponsor value
    	uniform_int_distribution<long long> cost_range(1, 300);   // instrument cost
    	uniform_int_distribution<long long> inst_id(ins/3, ins); 
    	fout << exp <<" "<< ins << '\n';
    	for(int j = 1; j <= exp; ++j)
    	{
    		fout << (pay_range(gen)*(999983))%300+1 << " ";
    		vector<int> this_ins;
    		int K = ((inst_id(gen)*(1000003))%ins)/3+1;
    		for(int k = 1; k <= K; ++k)
    		{
    			int id = inst_id(gen) % ins + 1;
                this_ins.push_back(id);
    		}
    		sort(this_ins.begin(), this_ins.end());
    		this_ins.erase(unique(this_ins.begin(), this_ins.end()), this_ins.end());
    		for(int k = 0; k < this_ins.size(); ++k)
    		{
    			fout<<this_ins[k];
    			fout<<" ";
    		}
    		fout<<'\n';
    	}
    	for(int j = 1; j <= ins; ++j) fout<<(cost_range(gen)*(1299709)%300+1)<<" ";
    	fout<<"\n";
    	fout.close();
	}
	return 0;
}