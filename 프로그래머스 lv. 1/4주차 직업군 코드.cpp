#include <string>
#include <vector>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    string temp = "";//임시적으로 table의 요소들을 받는 변수
    int score = 6;
    vector<int> sum = {0, 0, 0, 0, 0};//각 분야별 언어 점수 * 선호도 점수 들어가는 벡터
    //언어를 못 찾아도 default로 0점이 있으므로 굳이 언어 찾았는지 여부 확인할 필요X
    int num = 0;

    for(int i = 0; i < languages.size(); i++){
        for(int j = 0; j < table.size(); j++){            
            for(int p = 0; p < table[j].size(); p++){
                if(table[j][p] == ' '){
                    if(languages[i] == temp){
                        num = preference[i] * score;
                        sum[j] = sum[j] + num;
                        num = 0;
                    }
                    else{
                        score--;
                        temp = "";
                    }
                }
                else if(p == table[j].size() - 1){ //끝에 도달했을 경우 자동으로 넘어가지 않도록 case분류를 한번 더 해준다.
                    temp = temp + table[j][p];
                    if(temp == languages[i]){
                        num = preference[i] * score;
                        sum[j] = sum[j] + num;
                        num = 0;
                    }
                    else{
                        temp = "";
                        score--;
                    }
                }
                else{
                    temp = temp + table[j][p];
                }
            }
            score = 6;
            temp = "";
        }
    }

    int max = sum[0];
    int index = 0;
    for(int q = 1; q < sum.size(); q++){
        if(max < sum[q]){
            max = sum[q];
            index = q;
        }
        else if(max == sum[q]){
            if(table[index][0] > table[q][0]){
                max = sum[q];
                index = q;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }

    for(int r = 0; r < table[index].size(); r++){
        if(table[index][r] == ' '){
            break;
        }
        else{
            answer = answer + table[index][r];
        }
    }

    return answer;
}


//=================================================
//같은 문제 두번째 버젼
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> table, vector<string> languages, 
                vector<int> preference) {
    string answer = "";
    vector <int> job_score={0,0,0,0,0};
    string single_language;
    int prefer_score;
    
    //점수 합산 -> job_score에 추가시키기
    for(int i=0; i<languages.size(); i++){
        single_language = languages[i];  //python
        prefer_score=preference[i];    //7
        
        for(int j=0; j<table.size(); j++){
            string table_word="";
            int table_score=6;
            
            for(int k=0; k<table[j].size(); k++){
                if( table[j][k]==' '){
                    if(table_word==single_language){
                        job_score[j]+=(table_score*prefer_score);
                        break;
                    }
                    table_word="";
                    table_score--;
                }
                else if (k==table[j].size()-1){
                     table_word.push_back(table[j][k]);
                    if(table_word==single_language){
                        job_score[j]+=(table_score*prefer_score);
                        break;
                    }
                    table_word="";
                    table_score--;
                }
                else{
                    table_word.push_back(table[j][k]);
                }
            }
        }
    }
   
    //job_score 에서 index 찾기
    int max=-100;
    int max_index;
    
    string a;
    string b;
    string a_word;
    string b_word;
    vector <string> result;
    
    
    for(int i=0; i<job_score.size(); i++){
        if(max<job_score[i]){
            max=job_score[i];
            max_index=i;
        }
        else if(max==job_score[i]){ //사전식 비교
            //max_index ,  i 
            a= table[max_index];
            b= table[i];
            a_word="";
            b_word="";
            result={};
            for(int j=0; j<a.size(); j++){
                if(a[j]==' '){
                    break;
                }
            a_word.push_back(a[j]);
            }
            result.push_back(a_word);
            for(int j=0; j<b.size(); j++){
                if(b[j]==' '){
                    break;
                }
            b_word.push_back(b[j]);
            }
            result.push_back(b_word);
            
            sort(result.begin(), result.end());
            if(result[0]==b_word){
                max=job_score[i];
                max_index=i;
                
            }
        }
    }
   
    //해당 index에서 답 추출
    string answer_string = table[max_index];
    for(int i=0; i<answer_string.size(); i++){
        if(answer_string[i]==' '){
            break;
        }
        answer.push_back(answer_string[i]);
    }
    
    return answer;
    
}
