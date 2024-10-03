/* 

The algorithm I am using is : 
1. Calculating the initial effor for each of the assignee. I'm using map<string,int> named as effort. map<string,int> means map<name,his_effort>.
2. Finding and storing all the index that has a status 'in-review'. Storing this info in a pair<int,int> of vectors named in_review. pair<int,int> means pair<index,estimateHours>.  Doing this because, I want to sort the 'in-review' status tasks by their estimateHours in ascending order. I'm using a custom comparetor for this. 
3. after that, from the effort map I'm taking the name and the respective effort to a priority queue named sorted_by_effort. The priority queue is a max heap here. This is because, I want the person with maximum effort to be assigned to the lowest estimateHours task. 
4. There is an edge case which is, when assigneeName and current reviewer name is same, I am not assigning him in his own task. Rather, assigning the current second maximum effort assignee from the priority queue as reviewer for that task. Also pushing the current assignee back to the priority queue. 
5. I have taken the tasks vector as reference so the changes are reflected in the original tasks.
6. Overall Time Complexity of my algorithm is: O(NlogN) where N represents number of tasks are there in the input. 
*/


/* 
tasks = [
  {
    taskId: 1,
    assigneeName: "Jim",
    reviewerName: null,
    status: "in-review",
    estimateInHours: 10
  },
  {
    taskId: 2,
    assigneeName: "Jack",
    reviewerName: null,
    status: "in-review",
    estimateInHours: 10
  }
]

tasks = [
  {
    taskId: 1,
    assigneeName: "Shamim",
    reviewerName: null,
    status: "todo",
    estimateInHours: 10
  },
  {
    taskId: 2,
    assigneeName: "Shakil",
    reviewerName: "John",
    status: "in-review",
    estimateInHours: 20
  },
  {
    taskId: 3,
    assigneeName: "Jannat",
    reviewerName: null,
    status: "in-review",
    estimateInHours: 30
  },
  {
    taskId: 4,
    assigneeName: "Abir",
    reviewerName: null,
    status: "in-review",
    estimateInHours: 40
  },
  {
    taskId: 5,
    assigneeName: "Abrar",
    reviewerName: null,
    status: "in-review",
    estimateInHours: 50
  }
]



*/


#include <bits/stdc++.h>
using namespace std;

struct task{
    int taskId;
    string assigneeName;
    string reviewerName;
    string status;
    int estimateHours;
    task(){}
    task(int taskId, string assigneeName, string reviewerName, string status, int estimateHours)
    {
        this->taskId = taskId;
        this->assigneeName = assigneeName;
        this->reviewerName = reviewerName;
        this->status = status;
        if(this->status == "") this->status = "NULL";
        this->estimateHours = estimateHours;
    }
};


void recommend_reviewer(vector<task> &tasks)
{
    vector<pair<int,int>> in_review;
    map<string,double> effort;
    for(int i = 0; i < tasks.size(); i++)
    {
        auto [taskId,assigneeName,reviewerName,status,estimateHours] = tasks[i];
        if(reviewerName == "NULL" && status == "in-review")
        {
            in_review.push_back({i,estimateHours});
        }
        effort[assigneeName] += estimateHours;
        if(reviewerName != "NULL")
        {
            effort[reviewerName] += (1.00*estimateHours)/3;
        }
    }
    sort(in_review.begin(),in_review.end(),[](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });
    
    priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>>> sorted_by_effort;
    for(auto [name,cur_effort]: effort)
    {
        sorted_by_effort.push({name,cur_effort});
    } 
    for(auto [idx,estimateHours]: in_review)
    {
        auto [name,cur_effort] = sorted_by_effort.top();
        sorted_by_effort.pop();

        if(tasks[idx].assigneeName != name)
        {
            tasks[idx].reviewerName = name;
        }else 
        {
            auto [name2,cur_effort2] = sorted_by_effort.top();
            sorted_by_effort.pop();
            tasks[idx].reviewerName = name2;
            sorted_by_effort.push({name,cur_effort}); 
        }
    }
}

void print(vector<task> &tasks)
{
    cout << "tasks = [" << endl;
    for(auto [taskId,assigneeName,reviewerName,status,estimateHours] : tasks)
    {
        cout << "{" << endl;
        cout << "taskId : " << taskId << "," << endl;
        cout << "assigneeName : " << assigneeName << "," << endl;
        cout << "reviewerName : " << reviewerName << "," << endl;
        cout << "status : " << status << "," << endl;
        cout << "estimateHours : " << estimateHours << endl;
        cout << "}," << endl;
    }
}


int main()
{
    vector<task> tasks;

    // tasks.push_back(task(1,"John","NULL","todo",4));
    // tasks.push_back(task(2,"Jane","John","in-review",8));
    // tasks.push_back(task(3,"Jim","NULL","in-review",6));


    // tasks.push_back(task(1,"Jim","NULL","in-review",10));
    // tasks.push_back(task(2,"Jack","NULL","in-review",10));
    


    tasks.push_back(task(1,"Shamim","NULL","in-review",2));
    tasks.push_back(task(2,"Shakil","NULL","todo",3));
    tasks.push_back(task(3,"Rifa","NULL","in-progress",4));
    tasks.push_back(task(4,"Sneha","Shakil","in-review",5));
    tasks.push_back(task(5,"Jannat","NULL","in-review",6));

    recommend_reviewer(tasks);

    print(tasks);

    // for user input in console
    // int n; 
    // cin >> n;
    // for(int i = 0; i < n; i++)
    // {
    //     int taskId;
    //     string assigneeName;
    //     string reviewerName;
    //     string status;
    //     int estimateHours;
    //     cin >> taskId >> assigneeName >> reviewerName >> status >> estimateHours;
    //     tasks.push_back(task(taskId,assigneeName,reviewerName,status,estimateHours));
    // }

}