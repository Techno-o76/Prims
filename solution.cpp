#include <bits/stdc++.h>
using namespace std;


bool solve(long double p, long double a, long double b,vector<long double>&Chakravyuha){
    queue<vector<long double>>q;
    q.push({0,p,a,b,-1});
    
    while(!q.empty()){
        long double indx = q.front()[0];
        long double curPower = q.front()[1];
        long double canSkipFights = q.front()[2];
        long double numberOfRechargesLeft = q.front()[3];
        long double prevFight = q.front()[4];
        q.pop();
        
        if(indx>=11) return true;
        
        // skip current fight
        if(canSkipFights>0){
            q.push({indx+1,curPower,canSkipFights-1,numberOfRechargesLeft,prevFight});
        }
        
        long double curAttack;
        
        if((indx==3&&prevFight==2) || (indx==7&&prevFight==6)){
            if(indx==3&&prevFight==2) {
                curAttack = Chakravyuha[3] + Chakravyuha[2]/2;
            }
            else{
                curAttack = Chakravyuha[7]+Chakravyuha[6]/2;
            }
        }
        else{
            curAttack = Chakravyuha[indx];
        }
        
        // wihoutRecharge
        if(curPower>=curAttack){
            q.push({indx+1,curPower-curAttack,canSkipFights,numberOfRechargesLeft,indx});
        }
        
        // userRecharge
        if(numberOfRechargesLeft>0 && p>=curAttack){
            // recharge after fight if curPower>=curAttack
            if(curPower>=curAttack){
                q.push({indx+1,p,canSkipFights,numberOfRechargesLeft-1,indx});
            }
            
            // recharge before fight
            q.push({indx+1,p-Chakravyuha[indx],canSkipFights,numberOfRechargesLeft-1,indx});
        }
    }
    
    return false;
}

int main() {
    long double p; // AbhimanyuPower
    long double a; // Skip the fight
    long double b; // Recharge 
    
    cin>>p>>a>>b;
    
    vector<long double>Chakravyuha(11);
    
    for(auto &it:Chakravyuha){
        cin>>it;
    }
    
    bool isPossibleToReachPandavas = solve(p,a,b,Chakravyuha);
    if(isPossibleToReachPandavas){
        cout<<"Possible to Reach to Pandavas"<<endl;
    }
    else{
        cout<<"Not Possible to Reach to Pandavas"<<endl;
    }
    return 0;
}