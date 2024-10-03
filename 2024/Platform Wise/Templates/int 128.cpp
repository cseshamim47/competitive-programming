#define int128 __int128 
istream &operator>>(istream &is,int128 &v) {
    string s;
    is>>s;
    v=0;
    for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
    if(s[0]=='-') v*=-1;
    return is;
}

ostream &operator<<(ostream &os,const int128 &v) {
    if(v==0) return (os<<"0");
    __int128 num=v;
    if(v<0) os<<'-',num=-num;
    string s;
    for(;num>0;num/=10) s.push_back((char)(num%10)+'0');
    reverse(s.begin(),s.end());
    return (os<<s);
}