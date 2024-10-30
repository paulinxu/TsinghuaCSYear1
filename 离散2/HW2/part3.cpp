#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct process
{
    double v;
    double s;
    double pi;
    double earliest_start;
    int pre_count;
    vector<int> pre_ids;
    vector<double> pre_times;
};

double getTime(process x, double w)
{
    int count = 1;
    double sum = 0;
    while (true)
    {
        sum += min(x.s, w / count / x.v);
        w -= min(w , count * x.v * x.s);
        count ++;
        
        if (w <= 0)
        {
            break;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<process> processes;
    vector<double> velocities;
    vector<double> times;

    for (int i = 0 ; i < n-1 ; i ++)
    {
        double v;
        cin >> v;
        velocities.push_back(v);
    }
    for (int i = 0 ; i < n-1 ; i ++)
    {
        double s;
        cin >> s;
        times.push_back(s);
    }
    for (int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        
        process temp;
        temp.pre_count = x;

        for (int j = 0 ; j < x ; j ++)
        {
            int pre_id;
            double pre_time;
            cin >> pre_id >> pre_time;
            temp.pre_ids.push_back(pre_id-1);
            temp.pre_times.push_back(pre_time);
            // cout << pre_id << ' ' << pre_time << endl; /// delete
        }
        processes.push_back(temp);
    }
    for (int i = 0 ; i < n-1 ; i ++)
    {
        processes[i].v = velocities[i];
        processes[i].s = times[i];
    }

    // for (int i = 0 ; i < n ; i ++)
    // {
    //     cout << i << "-" << processes[i].v << "-" << processes[i].s << "-" << processes[i].pre_count << endl;
    //     for (int j = 0 ; j < processes[i].pre_count ; j ++)
    //     {
    //         cout << "Prereq: " << processes[i].pre_ids[j] << " " << processes[i].pre_times[j] << endl;
    //     }
    // }

    vector<process> sorted(n);
    vector<int> original(n,0);
    vector<bool> done(n, false); 

    int pos = 0;
    int i = 0;
    
    while (pos < n)
    {
        if (!done[i])
        {
            
            bool valid = true;
            
            for (int j = 0 ; j < processes[i].pre_count ; j ++)
            {
                // cout << 'd' << processes[i].pre_count << endl;
                if(!done[processes[i].pre_ids[j]])
                {
                    valid = false;
                }
            }

            if (valid == true)
            {
                //cout << i << endl;
                sorted[pos] = processes[i];
                original[pos] = i;
                done[i] = true;
                pos++;
            }
        }
        i ++;
        i %= n;
    }

    processes[original[0]].pi = 0;

    for (int j = 1 ; j < n ; j ++)
    {
        double new_pi = 0;
        for (int i = 0; i < sorted[j].pre_count ; i ++)
        {
            cout << (processes[sorted[j].pre_ids[i]].pi) + (getTime(processes[sorted[j].pre_ids[i]] , sorted[j].pre_times[i]));
            cout << ' ' << (getTime(processes[sorted[j].pre_ids[i]] , sorted[j].pre_times[i])) << endl;
            new_pi = max(new_pi, (processes[sorted[j].pre_ids[i]].pi) + (getTime(processes[sorted[j].pre_ids[i]] , sorted[j].pre_times[i])));
        }
        processes[original[j]].pi = new_pi;
        //cout << processes[original[i]].pi << endl;
    }

    // cout << fixed << setprecision(2);
    // cout << processes[n-1].pi << endl;




}