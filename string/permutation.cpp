bool valid(int c1[26],int c2[26]){
    for(int i=0;i<26;i++){
        if(c1[i]!=c2[i])
        {
            return 0;
        }
    }
    return 1;
}
    bool checkInclusion(string s1, string s2) {
        int c1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            c1[index]++;
        }
        int i=0;
        int k=s1.length();
        int c2[26]={0};
        //first window
        while(i<k && i<s2.length()){
             int index=s2[i]-'a';
            c2[index]++;
            i++;
        }
        if(valid(c1,c2))
        {return 1;}
        //next window
        while(i<s2.length()){
            char newchar=s2[i];
            int index=newchar - 'a';
            c2[index]++;

            char old=s2[i-k];
            index=old-'a';
            c2[index]--;
            i++;
         if(valid(c1,c2))
        { return 1;}
        }
        return 0;
    }