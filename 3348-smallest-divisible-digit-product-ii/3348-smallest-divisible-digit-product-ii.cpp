class Solution {
private:
    int need(long long a,long long b,long long c,long long d){
        a=max(0LL,a); b=max(0LL,b);
        c=max(0LL,c); d=max(0LL,d);

        int x=d+c+b/2+a/3;
        b%=2; a%=3;

        if(b==1&&a==2) x+=2;
        else if(b==1||a) x++;

        return x;
    }

    string make(long long a,long long b,long long c,long long d,int len){
        a=max(0LL,a); b=max(0LL,b);
        c=max(0LL,c); d=max(0LL,d);

        string ans="";

        while(d--) ans+='7';
        while(c--) ans+='5';

        int e=a/3,f=b/2;
        a%=3; b%=2;

        if(b==1&&a==2){ ans+="26"; a=0; b=0; }
        else if(b==1&&a==1){ ans+='6'; a=0; b=0; }
        else if(b==1){ ans+='3'; b=0; }
        else if(a==2){ ans+='4'; a=0; }
        else if(a==1){ ans+='2'; a=0; }

        while(f--) ans+='9';
        while(e--) ans+='8';

        while(ans.size()<len) ans+='1';

        sort(ans.begin(),ans.end());
        return ans;
    }

    bool ok(long long a,long long b,long long c,long long d,int len){
        return need(a,b,c,d)<=len;
    }

public:
    string smallestNumber(string s,long long t){
        long long a=0,b=0,c=0,d=0,x=t;

        while(x%2==0) a++,x/=2;
        while(x%3==0) b++,x/=3;
        while(x%5==0) c++,x/=5;
        while(x%7==0) d++,x/=7;

        if(x>1) return "-1";

        int n=s.size();

        vector<long long> A(n+1,a),B(n+1,b),C(n+1,c),D(n+1,d);

        int z=-1;

        for(int i=0;i<n;i++){
            int v=s[i]-'0';

            if(v==0){
                z=i;
                break;
            }

            A[i+1]=A[i]-(v==2||v==6?1:v==4?2:v==8?3:0);
            B[i+1]=B[i]-(v==3||v==6?1:v==9?2:0);
            C[i+1]=C[i]-(v==5);
            D[i+1]=D[i]-(v==7);
        }

        if(z==-1&&ok(A[n],B[n],C[n],D[n],0)) return s;

        int lim=(z==-1)?n-1:z;

        for(int i=lim;i>=0;i--){
            for(int j=s[i]-'0'+1;j<=9;j++){

                long long p=A[i]-(j==2||j==6?1:j==4?2:j==8?3:0);
                long long q=B[i]-(j==3||j==6?1:j==9?2:0);
                long long r=C[i]-(j==5);
                long long w=D[i]-(j==7);

                if(ok(p,q,r,w,n-1-i)){
                    return s.substr(0,i)+to_string(j)+make(p,q,r,w,n-1-i);
                }
            }
        }

        int len=max(n+1,need(a,b,c,d));
        return make(a,b,c,d,len);
    }
};