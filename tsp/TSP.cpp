#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define V1 4

lli start;
priority_queue< pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>,

vector<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>>,
greater<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>> > p1;


lli hf(lli node,lli visited[],lli graph[][V1])
{
       
   visited[node]=1;
   
     
   lli min0=100000,min1=100000;
   lli i,z=0,heuristic=0;
   


   for(i=1;i<=V1;i++)
   {
      if(visited[i]==0)
    {    
     
       
      if(graph[node-1][i-1]<min0)
      min0=graph[node-1][i-1];
     
      if(graph[i-1][start-1]<min1)
      min1=graph[i-1][start-1];
   
      z=z+1;    
    }
       
   }    
   
   if(z>=1)  
   heuristic+=min0+min1;
   
   
   
   return heuristic;
}


void traversal(lli node,lli cost,lli visited[],lli graph[][V1])
{
   lli mx=-1;
   
    for(lli i=1;i<=V1;i++)
   { if(visited[i]>=mx)
     mx=visited[i];
   }
       
       

   visited[node]=mx+1;

   
   
   lli z=0;  
   lli visited1[V1+1][V1+1]={0};
   lli visited2[V1+1][V1+1]={0};
   vector<lli>path1[V1+1];
   
   for(lli i=1;i<=V1;i++)
   {
      if(visited[i]==0)
    {
      for(lli j=1;j<=V1;j++)
      {
          visited1[i][j]=visited[j];
       
          if(visited[j]>=1)
          visited2[i][j]=1;
          else
          visited2[i][j]=0;    
      }
         
      lli heur=hf(i,visited2[i],graph);
      lli obj=heur+graph[node-1][i-1]+cost;    
      p1.push({obj,{i,{node,{cost,visited1[i]}}}});          
 
      z=z+1;
    }
       
   }
   

   
   if(z>=1)
   {pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>> p2=p1.top();
    p1.pop();
   
    cost=p2.second.second.second.first + graph[p2.second.second.first-1][p2.second.first-1];
 
   
    traversal(p2.second.first,cost,p2.second.second.second.second,graph);
   }
   
   else
   {
     vector<pair<lli,lli>>finalpath;
       
     cout<<"Path: ";  
     
     for(lli i=1;i<=V1;i++)
     finalpath.push_back({visited[i],i});
       
     sort(finalpath.begin(),finalpath.end());
     
     for(lli i=0;i<finalpath.size();i++)
     cout<<finalpath[i].second<<" ";
       

       
     cout<<"1 ";  
     cout<<"\n";
 
     cout<<"Cost: "<<cost+graph[node-1][start-1];
     return;
   }
       
   
}    

int main()
{
  start=1;
  
  lli visited[V1+1]={0};
 
 
  lli graph[][V1] =
  {
      {0,10,50,40},
      {10,0,20,60},
      {50,20,0,30},
      {40,60,30,0},
  };
 
   traversal(start,0,visited,graph);
 
 
  return 0;  
   
}
