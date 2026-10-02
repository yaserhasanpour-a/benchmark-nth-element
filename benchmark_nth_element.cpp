#include<algorithm>
#include<chrono>
#include<iostream>
#include<vector>
#include<random>
using namespace std;
using clk = chrono::steady_clock;
double median_by_sort(vector<int>v)
{
	sort(v.begin(), v.end());
	size_t n = v.size();
	if(n % 2 == 1)
		return v[n/2];
	else
		return 0.5 * (v[n/2] + v[n/2 -1]);
}
double median_by_nth_element(vector<int>v)
{
	size_t n = v.size();
	auto mid1 = v.begin() + n / 2;
	nth_element(v.begin(), mid1, v.end());
	int hi = *mid1;
	if( n % 2 == 1)
		return hi;
	auto mid2= v.begin() +  (n / 2 - 1);
	nth_element(v.begin(), mid2 , mid1);
	int lo = *mid2;
	return 0.5 * (lo + hi);
}
int main()
{
	const size_t N = 10000000;
	vector<int>data;
	data.reserve(N);
	mt19937 rng(12345);
	uniform_int_distribution<int>dist(1, 1000000);
	for(int i=0; i<N; ++i)
	        data.push_back(dist(rng));
	auto start0 = clk::now();
	auto m1=median_by_sort(data);
	auto end0 = clk::now();
	auto sort_ms = chrono::duration_cast<chrono::milliseconds>(end0-start0).count();
	cout<<"N="<<N<<'\n';
	cout<<"midian by Sort Time="<<m1<<'\n';
	cout<<"Time by sort= " <<sort_ms<<'\n';
    
	auto start1 = clk::now();
	auto m2=median_by_nth_element(data);
	auto end1 = clk::now();
	auto nth_ms = chrono::duration_cast<chrono::milliseconds>(end1-start1).count();
	cout<<"midian by nts_element="<<m2<<'\n';
	cout<<"Time by nth_element=  "<<nth_ms<<'\n';

}
