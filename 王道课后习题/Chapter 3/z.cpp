    while(p2!=NULL){
        s = p2->next;
        p2->next = str2->next;
        str2->next = p2;
        p2 = s;
    }
    L2 = str2;