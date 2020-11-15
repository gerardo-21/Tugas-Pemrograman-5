// Implementasi Priority Scheduling dalam bahasa C++
#include<bits/stdc++.h>
using namespace std;

//struct untuk mensimulasikan sebuah proses
struct Process
{
	// process id untuk menandai proses
    int pid;
    // CPU burst time dari proses
    int bt;
    // prioritas setiap proses
    int priority;
};

// fungsi untuk mengurutkan proses berdasarkan prioritas
// yang memiliki prioritas lebih tinggi (variabel priority paling besar) dieksekusi duluan
bool sortProcesses(Process a, Process b)
{
    return (a.priority > b.priority);
}

// fungsi untuk menghitung waiting time dari semua proses
void findWaitingTime(Process proc[], int n,
                     int wt[])
{
    // waiting time proses pertama = 0
    wt[0] = 0;

    // menghitung waiting time
    for (int  i = 1; i < n ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1] ;
}

// Fungsi untuk menghitung turn around time
void findTurnAroundTime( Process proc[], int n,
                         int wt[], int tat[])
{
    // menghitung turn around time dengan menambahkan burst time proses ke-i dengan waiting time proses ke-i
    for (int  i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

//Fungsi untuk menghitung waktu rata-rata
void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, wt, tat);

    //Mengoutput semua proses dengan detil burst time, waiting time dan turn around time
    cout << "\nProcesses  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    // Menghitung waktu tunggu total dan total turn around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i]
             << "\t\t  " << tat[i] <<endl;
    }

    //Mengoutput average waiting time dan average turn around time
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

// Fungsi utama untuk mensimulasikan Priority Scheduling dan mengeluarkan outputnya
void priorityScheduling(Process proc[], int n)
{
    // Mengurutkan proses berdasarkan prioritas
    sort(proc, proc + n, sortProcesses);

    // Mengoutput urutan proses yang dieksekusi
    cout<< "Order in which processes gets executed \n";
    for (int  i = 0 ; i <  n; i++)
        cout << proc[i].pid <<" " ;

    findavgTime(proc, n);
}

// Code untuk melakukan cek algoritme
int main()
{
    // Proses id 1 memiliki burst time 10, dan prioritas 2
    // Proses id 2 memiliki burst time 5, dan prioritas 0
    // Proses id 3 memiliki burst time 8, dan prioritas 1
    Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
