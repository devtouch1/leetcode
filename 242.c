bool isAnagram(char * s, char * t){
    if(strlen(s) != strlen(t)) return false;

    int arr[26] = {0};

    for(int i = 0; i < strlen(s); i++){
        arr[(int)s[i]-'a']++;
        arr[(int)t[i]-'a']--;
    }
    for(int j=0; j<26;j++){
        if(arr[j]!=0) return false;
    }
    return true;

}