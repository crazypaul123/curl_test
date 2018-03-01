#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
    false=0,
    true
}BOOL;
BOOL  getUrl(char *filename)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    if((fp=fopen(filename,"w"))==NULL)
        return false;
    struct curl_slist *headers=NULL;
    headers=curl_slist_append(headers,"Accept:Agent-007");
    curl=curl_easy_init();
    if(curl){
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER,headers);
        curl_easy_setopt(curl,CURLOPT_URL,"www.baidu.com");
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
        curl_easy_setopt(curl,CURLOPT_HEADERDATA,fp);
        res=curl_easy_perform(curl);
        if(res!=0){
            curl_slist_free_all(curl);
            curl_easy_cleanup(curl);
        }
        fclose(fp);
        return true;
    }
}
void main()
{
    getUrl("get.html");
}
