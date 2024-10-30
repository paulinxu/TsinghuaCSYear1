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

double getTime(process x, double total_work)
{
    int time_elapsed = 1;
    double total_time = 0;
    while (true)
    {
        double remainder_time = total_work / time_elapsed / x.v;
        total_time += min(x.s, remainder_time);

        double work = time_elapsed * x.v * x.s;
        total_work -= min(total_work , work);

        if (total_work <= 0)
        {
            break;
        }

        time_elapsed ++;
    }
    return total_time;
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
    vector<int> new_index(n,0);
    vector<bool> done(n, false); 

    int i = 0; 
    int j = 0;

    while (i < n){ 
        
        if (!done[j])
        {
            bool valid = true;
            for (int x = 0 ; x < processes[j].pre_ids.size(); x ++)
            {
                if (done[processes[j].pre_ids[x]] == false)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                sorted[i] = processes[j];

                for (int k = 0 ; k < sorted[i].pre_ids.size() ; k ++)
                {
                    sorted[i].pre_ids[k] = new_index[sorted[i].pre_ids[k]];
                }

                new_index[j] = i;
                done[j] = true;
                i ++; 
            }
        }
        j ++;
        j %= n;
    }

    sorted[0].pi = 0;

    for (int j = 1 ; j < n ; j ++)
    {
        double new_pi = 0;
        for (int i = 0; i < sorted[j].pre_ids.size() ; i ++)
        {
            double weight = getTime(sorted[sorted[j].pre_ids[i]], sorted[j].pre_times[i]);
            double pi_i = (sorted[sorted[j].pre_ids[i]].pi);

            // cout << "j=" << j << ", i=" << i << " ::" << pi_i  << ' ' <<  weight << endl;

            new_pi = max(new_pi, (pi_i + weight));
        }
        sorted[j].pi = new_pi;
    }

    cout << fixed << setprecision(2);
    cout << sorted[new_index[n-1]].pi << endl;

}