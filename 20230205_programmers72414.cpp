#include <string>
#include <vector>
using namespace std;
//구조체
struct vedioInfo{
    int start,end;
};
const int maxi = 360001;
int play,addTime;
vector<vedioInfo> vedio;//비디오 
long long CountPeople[maxi];//조회수
string answer = "";//정답

//숫자로 바꾸기
void ChangeNum(string play_time, string adv_time, vector<string> logs){
    play = stoi(play_time.substr(0,2))*3600+stoi(play_time.substr(3,2))*60+stoi(play_time.substr(6,2));
    addTime = stoi(adv_time.substr(0,2))*3600+stoi(adv_time.substr(3,2))*60+stoi(adv_time.substr(6,2));
    for(int i=0;i<logs.size();i++){
        int startTime = stoi(logs[i].substr(0,2))*3600+stoi(logs[i].substr(3,2))*60+stoi(logs[i].substr(6,2));
        int endTime = stoi(logs[i].substr(9,2))*3600+stoi(logs[i].substr(12,2))*60+stoi(logs[i].substr(15,2));
        vedio.push_back({startTime,endTime});
    }
}
//조회수 구하기
void Hits(){
    //영상 출입 여부
    for(int i=0;i<vedio.size();i++){
        int startVedio = vedio[i].start;
        int endVedio = vedio[i].end;
        CountPeople[startVedio]+=1;
        CountPeople[endVedio]-=1;
    }
    //각 시각별 조회수
    for(int i=1;i<=play;i++) CountPeople[i]+=CountPeople[i-1];
    //각 시각별 누적 조회수
    for(int i=1;i<=play;i++) CountPeople[i]+=CountPeople[i-1];
}
//광고 삽입
int AddAdv(){
    int beginAdv = 0;long long people = CountPeople[addTime-1];
    for(int i=1;i<=play+1-addTime;i++){
        //더 많은 누적 조회수
        if(CountPeople[i+addTime-1]-CountPeople[i-1]>people){//광고 시작부터 끝까지
            beginAdv = i;
            people = CountPeople[i+addTime-1]-CountPeople[i-1];
        }
    }
    return beginAdv;
}
//시간으로 바꾸기
string ChangeTime(int x){
    //시,분,초
    string times = "";
    int hours = x/3600;
    int minutes = (x/60)%60;
    int seconds = x%60;
    //형식 맞추기
    times+=(hours>9?to_string(hours)+":":"0"+to_string(hours)+":");
    times+=(minutes>9?to_string(minutes)+":":"0"+to_string(minutes)+":");
    times+=(seconds>9?to_string(seconds):"0"+to_string(seconds));
    return times;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    ChangeNum(play_time, adv_time,logs);//숫자로 바꾸기
    Hits();//조회수 구하기
    answer = ChangeTime(AddAdv());//광고 삽입
    return answer;
}
