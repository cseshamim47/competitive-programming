#include <bits/stdc++.h>
using namespace std;

class User{
    public:
    string name,phone;
    User(){}
    User(string name, string phone){
        this->name = name;
        this->phone = phone;
    }
};

class Message{
    public: 
    User sender;
    User receiver;
    string message;
    int curTime;
    Message(){}
    Message(User sender, User receiver, string message,int curTime){
        this->sender = sender;
        this->receiver = receiver;
        this->message = message;
        this->curTime = curTime;
    }
};

class TopTen{
    public: 
    User sender;
    User receiver;
    TopTen(){}
    TopTen(User sender, User receiver){
        this->sender = sender;
        this->receiver = receiver;
    }
};

struct TopTenComparator {
    bool operator()(TopTen l, TopTen r) {
        return l.sender.phone < r.sender.phone;
    }
};


class ChattingApp{
    public: 
    int timer = 0;
    vector<Message> messages;

    void sendMessage(User sender, User receiver, string message)
    {
        messages.push_back(Message(sender,receiver,message,++timer));
    }

    void showUserMessaage(User user)
    {   
        vector<pair<int,int>> idx;
        int i = 0;
        for(auto [sender,receiver,message,curTime]: messages)
        {
            if(receiver.phone == user.phone)
            {
                idx.push_back({i,curTime});
            }
            i++;
        }

        sort(idx.begin(),idx.end(),[](pair<int,int> &a, pair<int,int> &b){
            return a.second > b.second;
        });

        for(auto [i,_]: idx)
        {
            auto [sender,receiver,message,curTime] = messages[i];   
            cout << "{" << endl;
            cout << "sender : " << sender.name << endl;
            cout << "phone : " << sender.phone << endl;
            cout << "Message : " << message << endl;
            cout << "}" << endl;
        }
    }

    void showTopTenMessage()
    {
        map<vector<string>,int> mp;
        vector<TopTen> tt;
        for(auto [sender,receiver,message,curTime]: messages)
        {
            vector<string> v;
            v.push_back(sender.phone);
            v.push_back(receiver.phone);
            sort(v.begin(),v.end());
            mp[v]++;
        }

        vector<pair<TopTen,int>> res;
        for(auto [sender,receiver,message,curTime]: messages)
        {
            vector<string> v;
            v.push_back(sender.phone);
            v.push_back(receiver.phone);
            sort(v.begin(),v.end());
            if(mp[v] > 0)
            {
                res.push_back({TopTen(sender,receiver),mp[v]});
                mp[v] = 0;
            }
        }
        
        sort(res.begin(),res.end(),[](pair<TopTen,int> &a, pair<TopTen, int> &b){
            return a.second > b.second;
        });
        
        cout << "[" << endl;
        for(int i = 0; i < min<int>(10,res.size()); i++)
        {
            auto &[x,cnt] = res[i];
            auto &[sender,receiver] = x;
            cout << "{" << endl;
            cout << "personA : " << sender.name << endl;
            cout << "personAPhone : " << sender.phone << endl;
            cout << "personB : " << receiver.name << endl;
            cout << "personBPhone : " << receiver.phone << endl;
            cout << "numberOfMessages : " << cnt << endl;
            cout << "}" << endl;
        }
        cout << "]" << endl;
    }

};

int main()
{
    User john("John","01717001473");
    User jane("jane","01717001472");
    User shamim("Shamim","01878042329");
    User rakib("Rakib","01717007071");

    ChattingApp app;
    app.sendMessage(john,jane,"hello!"); // john - jane
    app.sendMessage(jane,john,"hi"); // jane - john
    app.sendMessage(shamim,john,"why"); // shamim - john
    app.sendMessage(shamim,jane,"its working"); // shamim - jane
    app.sendMessage(shamim,john,"nice"); // shamim - john
    app.sendMessage(jane,rakib,"its time to submit"); // jane - rakib

    // app.showUserMessaage(john);

    app.showTopTenMessage();
    
}



/* 



*/