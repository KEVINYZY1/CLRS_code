#include <iostream>
#include <ctime>

using namespace std;

void print_utc_time(const time_t * t);
void print_localtime_detail(const time_t *t);

int main() {
   // current date/time based on current system
   time_t now = time(0);
   print_utc_time(&now);
   print_localtime_detail(&now);
   
   // convert now to string form
   char * dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
}

void print_utc_time(const time_t * t){
    // convert now to string form
    char * dt = ctime(t);
    cout << "The local date and time is:" << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(t);
    dt = asctime(gmtm);
    cout << "The UTC date and time is: " << dt << endl;
}

void print_localtime_detail(const time_t * t){

    cout << "Number of sec since January 1,1970:" << *t << endl;
    
    tm *ltm = localtime(t);

    // print various components of tm structure.
    cout << "Year" << 1970 + ltm->tm_year<<endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
}