#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char name[11]={"visitor"},code[11]={'0'},rep[126]={'\0'};
char name1[11]={'0'},code1[11]={'0'},name2[11]={'0'};
char title[26]={'0'},cont[126]={'0'},title1[26]={'0'},cont1[126]={'0'};
int a=0,c=0,n=1,m=0,pa=0;
char b=0;
void menu();
void menu2();
void menu21();
void menu3();
void menu22();
void signup ();
void signup1();
void signup2();
void post();
void show();
void show1(int a);
void search();
void search1();
void search2();
void search3();
void search4();
void reply();
void reply1();
void deletecode();
void deletepost();
void adminshow();



void menu() {
    printf("学生论坛\n");
    printf("0.退出系统\n");
    printf("1.登录/注册\n");
    printf("2.以游客身份登录\n");
    printf("3.管理员登录\n");
    printf("\n请输入您的操作：");
    scanf("%d", &n);
    while (1) {
        switch (n) {
            case 0:exit(0);
            case 1:{
                system("cls");
                signup();
                break;
            }
            case 2:{
                system("cls");
                signup1();
                break;
            }
            case 3:{
                system("cls");
                signup2();
                break;
            }
            default:printf("请重新输入：");break;
        }
        scanf("%d", &n);
    }
}

void menu2() {
    printf("0.主菜单\n");
    printf("1.发帖\n");
    printf("2.回帖\n");
    printf("3.看帖\n");
    printf("4.看帖（最新）\n");
    printf("5.搜索(标题)\n");
    printf("6.搜索(作者)\n");
    printf("7.搜索(回复者回复)\n");
    printf("8.搜索(帖子回复)\n");
    printf("9.个人空间\n");
    printf("\n请输入您的操作：");
    scanf(" %d",&n);
    while (1) {
        switch (n) {
            case 0:
            {
                system("cls");
                if (strcmp(name,"admin")==0)
                    menu22();
                else menu();break;
            }
            case 1:{
                system("cls");
                post();
                break;
            }
            case 2:{
                system("cls");
                reply1();
                break;
            }
            case 3:{
                system("cls");
                pa=0;
                menu3();break;
            }
            case 4:show();break;
            case 5:search();break;
            case 6:search1();break;
            case 7:search2();break;
            case 8:search4();break;
            case 9:search3();break;
            default:printf("请重新输入：");break;
        }
        scanf("%d", &n);
    }

}

void menu21() {
    printf("0.主菜单\n");
    printf("1.发帖\n");
    printf("2.回帖\n");
    printf("3.看帖\n");
    printf("4.看帖（最新）\n");
    printf("5.搜索(标题)\n");
    printf("6.搜索(作者)\n");
    printf("7.搜索(回复者回复)\n");
    printf("8.搜索(帖子回复)\n");
    printf("\n请输入您的操作：");
    scanf(" %d",&n);
    while (1) {
        switch (n) {
            case 0:menu();break;
            case 1:{
                system("cls");
                post();
                break;
            }
            case 2:{
                system("cls");
                reply1();
                break;
            }
            case 3:{
                system("cls");
                pa=0;
                menu3();
                break;
            }
            case 4:{
                system("cls");
                show();
                break;
            }
            case 5:{
                system("cls");
                search();break;
            }
            case 6:{
                system("cls");
                search1();
                break;
            }

            case 7:{
                system("cls");
                search2();
                break;
            }
            case 8:{
                system("cls");
                search4();break;
            }

            default:printf("请重新输入：");break;
        }
        scanf("%d", &n);
    }

}

void menu22() {
    printf("0.返回主菜单\n");
    printf("1.进入论坛\n");
    printf("2.查看用户账号和密码\n");
    printf("3.修改密码\n");
    printf("4.删帖\n");
    printf("\n请输入您的操作：");
    scanf("%d", &n);
    while (1) {
        switch (n) {
            case 0:{
                system("cls");
                menu();
                break;
            }
            case 1:{
                system("cls");
                menu2();
                break;
            }
            case 2:{
                system("cls");
                adminshow();

                break;
            }
            case 3:{
                system("cls");
                deletecode();
                break;
            }
            case 4:{
                system("cls");
                deletepost();
                break;
            }
            default:printf("请重新输入：");break;
        }
        scanf("%d", &n);
    }
}

void menu3(){
    FILE *fp;
    if ((fp= fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        return;
    }
    for (int j=0;j<=pa;j++) {
        system("cls");
        printf("0.主菜单\n");
        for (int i = 1; i <= 10; i++) {
            fscanf(fp, "%s", name2);
            if (feof(fp)) break;
            fscanf(fp, "%s", title);
            fscanf(fp, "%120s", cont);
            printf("%d.%s\n%s\n", i, title, cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
            }
            if (feof(fp)) {
                break;
            }
        }
    }
    if(!feof(fp)) printf("11.下一页\n");
    if(pa!=0) printf("12.上一页\n");
    printf("13.翻页\n");
    printf ("当前为第%d页",pa);
    printf("\n请输入您的操作：");
    scanf(" %d", &n);
    while (1) {
        if(pa==0) switch (n) {
                case 0:{
                    system("cls");
                    menu2();
                }
                case 1:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+1);
                    break;
                }
                case 2:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+2);
                    break;
                }
                case 3:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+3);
                    break;
                }
                case 4:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+4);
                    break;
                }
                case 5:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+5);
                    break;
                }
                case 6:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+6);
                    break;
                }
                case 7:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+7);
                    break;
                }
                case 8:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+8);
                    break;
                }
                case 9:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+9);
                    break;
                }
                case 10:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+10);
                    break;
                }
                case 11:{
                    system("cls");
                    fclose(fp);
                    pa++;
                    menu3();
                    break;

                }
                case 13:{
                    system("cls");
                    printf("请输入页数:");
                    scanf (" %d",&pa);
                    menu3();
                    break;
                }
                default:printf("请重新输入：");break;
            }
        if (feof(fp)) switch (n) {
            case 0:{
                system("cls");
                menu2();
            }
            case 1:{
                system("cls");
                fclose(fp);
                show1(pa*10+1);
                break;
            }
            case 2:{
                system("cls");
                fclose(fp);
                show1(pa*10+2);
                break;
            }
            case 3:{
                system("cls");
                fclose(fp);
                show1(pa*10+3);
                break;
            }
            case 4:{
                system("cls");
                fclose(fp);
                show1(pa*10+4);
                break;
            }
            case 5:{
                system("cls");
                fclose(fp);
                show1(pa*10+5);
                break;
            }
            case 6:{
                system("cls");
                fclose(fp);
                show1(pa*10+6);
                break;
            }
            case 7:{
                system("cls");
                fclose(fp);
                show1(pa*10+7);
                break;
            }
            case 8:{
                system("cls");
                fclose(fp);
                show1(pa*10+8);
                break;
            }
            case 9:{
                system("cls");
                fclose(fp);
                show1(pa*10+9);
                break;
            }
            case 10:{
                system("cls");
                fclose(fp);
                show1(pa*10+10);
                break;
            }
            case 12: {
                system("cls");
                fclose(fp);
                pa--;
                menu3();
                break;
            }
            case 13:{
                system("cls");
                fclose(fp);
                printf("请输入页数:");
                scanf (" %d",&pa);
                menu3();
                break;
            }
            default:printf("请重新输入：");break;
        }
        if (!feof(fp)&&pa!=0) switch (n) {
                case 0:{
                    system("cls");
                    menu2();
                }
                case 1:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+1);
                    break;
                }
                case 2:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+2);
                    break;
                }
                case 3:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+3);
                    break;
                }
                case 4:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+4);
                    break;
                }
                case 5:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+5);
                    break;
                }
                case 6:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+6);
                    break;
                }
                case 7:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+7);
                    break;
                }
                case 8:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+8);
                    break;
                }
                case 9:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+9);
                    break;
                }
                case 10:{
                    system("cls");
                    fclose(fp);
                    show1(pa*10+10);
                    break;
                }
                case 11:{
                    system("cls");
                    fclose(fp);
                    pa++;
                    menu3();
                    break;
                }
                case 12: {
                    system("cls");
                    fclose(fp);
                    pa--;
                    menu3();
                    break;
                }
                case 13:{
                    system("cls");
                    fclose(fp);
                    printf("请输入页数:");
                    scanf (" %d",&pa);
                    menu3();
                    break;
                }
                default:printf("请重新输入：");break;
            }
        scanf(" %d", &n);
    }

}

void signup(){
    FILE *fp;
    if ((fp = fopen("member.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        signup();
    }
    printf("\n");
    printf ("您已进入登陆/注册界面!!!\n");
    printf ("账号及密码必须不超过10位数字！！！\n");
    printf("请输入账号（输入stop，返回上一级）:");
    scanf(" %s",name);
    if(strcmp(name, "stop")==0){
        system("cls");
        menu();
    }
    printf("请输入密码:");
    scanf(" %s",code);
    if(name[10]!='\0'||code[10]!='\0')
    {
        printf ("您输入的字母和数字超过10位，请重新输入");
        for(int i=0;i<=10;i++){
            name[i]='\0',code[i]='\0';
        }
        fclose(fp);
        signup();
    }

    while (1)
    {
        fscanf (fp,"%s%s",name1,code1);
        if (strcmp(name,name1)==0&&strcmp(code,code1)){
            system("cls");
            printf("密码错误！！！\n");
            printf("密码错误！！！\n");
            printf("密码错误！！！\n");
            for(int i=0;i<=10;i++){
                name[i]='\0',code[i]='\0';
            }
            fclose(fp);
            signup();
            break;
        }
        if (strcmp(name,name1)==0&&strcmp(code,code1)==0){
            system("cls");
            printf("成功登录！！！\n");
            fclose(fp);
            menu2();
            break;
        }
        if (feof(fp)){
            fprintf(fp,"%10s %10s\n",name,code);
            fclose(fp);
            system("cls");
            printf("成功注册\n");
            if (strcmp(name,"visitor")==0)
            menu21();
            else menu2();
            break;
        }
    }
}

void signup1(){
    strcpy(name, "visitor");
    system("cls");
    menu21();
}

void signup2(){
    printf ("您已进入管理员登陆界面!!!\n");
    printf("请输入账号（输入stop，返回上一级）:");
    scanf("%s",name);
    if(strcmp(name, "stop")==0){
        system("cls");
        menu();
    }
    printf("请输入密码:");
    scanf("%s",code);
    if(strcmp(name, "admin")==0&&strcmp(code, "admin")==0){
        system("cls");
        menu22();
    }
    else{
        printf ("账号或密码错误！！！");
        for(int i=0;i<=10;i++){
            name[i]='\0',code[i]='\0';
        }
        signup2();
    }

}

void post (){
    FILE *fp;
    for (int i = 0; i <= 25; i++) {
        title[i] = '\0';
    }
    for (int i = 0; i <= 125; i++) {
        cont[i] = '\0';
    }
    if ((fp= fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        post();
    }
    fprintf(fp,"\n%10s ",name);
    printf("请输入标题(标题字数不超过12个汉字（一个汉字相当于2个英文字符)（输入stop，返回上一级）:");
    scanf(" %s",title);
    if (strcmp(title, "stop") == 0) {
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    while(title[25] != '\0') {
            printf("您输入的标题字数超过要求，请重新输入；");
            for (int i = 0; i <= 25; i++) {
                title[i] = '\0';
            }
            scanf(" $s", title);
    }
    rewind(fp);
    while (100){
        fscanf(fp, "%s", name2);
        fscanf(fp, "%s", title1);
        if(feof(fp)) break;
        if(!strcmp(title,title1)){
            printf("标题已存在,请重新输入：");
            post();
        }
        fscanf(fp,"%s",cont);
        while(1){
            if (strcmp(cont, "stop") == 0) break;
            fscanf(fp,"%s",cont);
        }
    }
    fprintf(fp,"%25s",title);
    printf("请输入内容（(字数不超过65个汉字（一个汉字相当于2个英文字符)）:");
    scanf(" %s",cont);
    while(cont[125] != '\0') {
            printf("您输入的内容字数超过要求，请重新输入");
            for (int i = 0; i <= 125; i++) {
                cont[i] = '\0';
            }
            scanf(" $s", cont);
    }
    while(100){
        fprintf(fp," %125s",cont);
        if (strcmp(cont, "stop") == 0) break;
        for (int i = 0; i <= 125; i++) {
            cont[i] = '\0';
        }
        printf("输入完成，则输入stop，输入未完成，则继续输入:");
        scanf("%s",cont);
        while(cont[125] != '\0') {
                printf("您输入的内容字数超过要求，请重新输入");
                for (int i = 0; i <= 125; i++) {
                    cont[i] = '\0';
                }
                scanf("%s", cont);
        }
    }
    fclose(fp);
    system("cls");
    if (strcmp(name,"visitor")==0)
        menu21();
    else menu2();
}

void show (){
    FILE *fp;
    FILE *fp1;
    if ((fp= fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    while(!feof(fp)){
        fscanf(fp, " %s", name2);
        if (feof(fp)) break;
        fscanf(fp, " %s", title);
        printf("标题:");
        printf("%s  ",title);
        printf("作者:");
        printf("%s\n",name2);
        printf("    内容:");
        fscanf(fp," %s",cont);
        while(1){
            if (strcmp(cont, "stop") == 0) break;
            printf("  %s\n",cont);
            fscanf(fp," %s",cont);
        }
        printf("\n");
        if ((fp1= fopen("reply.txt", "a+")) == NULL) {
            printf("打开文件失败\n");
            system("cls");
            fclose(fp);
            if (strcmp(name,"visitor")==0)
                menu21();
            else menu2();
        }
        while (!feof(fp1)){
            fscanf(fp1, " %s", title1);
            fscanf(fp1, " %s", name2);
            if(!strcmp(title,title1)){
                printf("    回复者：");
                printf ("%s\n",name2);
                printf("    回复内容：");
                fscanf(fp1," %s",rep);
                printf ("  %s\n",rep);
                while(1){
                    if (strcmp(rep, "stop") == 0) break;
                    fscanf(fp1,"%s",rep);
                    printf ("%s\n",rep);
                }
                printf("\n");
            }
            else{
                fscanf(fp1," %s",rep);
                while(1){
                    if (strcmp(rep, "stop") == 0) break;
                    fscanf(fp1," %s",rep);
                }

            }
        }
    }
    fclose(fp1);
    fclose(fp);
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y')
    {
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {
        system("cls");
        show();
    }
}

void show1(int a){
    FILE *fp;
    if ((fp= fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        menu3();
    }
    for (int i=1;i<=a;i++){
        system("cls");
        if (feof(fp)){
            printf("帖子不存在！！！");break;
        }
        fscanf(fp, " %s", name2);
        fscanf(fp, " %s", title);
        printf("标题:");
        printf("%s  ",title);
        printf("作者:");
        printf("%s\n",name2);
        fscanf(fp," %s",cont);
        printf("  %s\n",cont);
        while(1){
            if (strcmp(cont, "stop") == 0) break;
            fscanf(fp," %s",cont);

            printf("    %s\n",cont);
        }
    }
    FILE *fp1;
    if ((fp1= fopen("reply.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        fclose(fp);
        menu3();
    }
    while (100){
        fscanf(fp1, " %s", title1);
        fscanf(fp1, " %s", name2);
        if(feof(fp1)) break;
        if(!strcmp(title,title1)){
            printf("    回复者：");
            printf ("%s\n",name2);
            //printf("    回复内容：");
            fscanf(fp1," %s",rep);
            printf ("%s\n",rep);
            while(1){
                if (strcmp(rep, "stop") == 0) break;
                fscanf(fp1," %s",rep);
                printf ("%s\n",rep);
            }
        }
        else{
            fscanf(fp1," %s",rep);
            while(1){
                if (strcmp(rep, "stop") == 0) break;
                fscanf(fp1," %s",rep);
            }
        }
    }
    fclose(fp1);
    fclose(fp);
    printf("是否评论（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        reply();
        system("cls");
        menu3();
    }
    else {
        system("cls");
        pa=a/10;
        menu3();
    }
}

void search() {
    FILE *fp;
    system("cls");
    if ((fp = fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        search();
    }
    printf("请输入搜索内容(标题)：");
    scanf(" %s", title1);
    c=0;
    while (!feof(fp)) {
        fscanf(fp, " %s", name2);
        fscanf(fp, " %s", title);
        n = 0;
        for (int i = 0; i < strlen(title1); i++) {
            m = n;
            for (int j = 0; j < strlen(title1); j++) {
                if (title[i] == title1[j]) {
                    n++;
                    break;
                }
            }
            if (n == m) {
                n = 0;
                break;
            }
        }
        if (n > 0) {
            printf("标题:");
            printf("%s  ", title);
            printf("作者:");
            printf("%s\n", name2);
            //printf("    内容:");
            fscanf(fp," %s",cont);
            printf("%s\n",cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, " %s", cont);
                printf("%s\n", cont);
            }
            c++;
            printf("\n");
        }
        else {
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, " %s", cont);
            }
        }
    }
    fclose(fp);
    if (c==0) printf ("请更换关键词搜索！！！\n");
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {
        system("cls");
        search();
    }
}

void search1() {
    FILE *fp;
    system("cls");
    if ((fp = fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        search1();
    }
    printf("请输入搜索内容(作者)：");
    scanf(" %s", name1);
    c=0;
    while (!feof(fp)) {
        fscanf(fp, "%s", name2);
        fscanf(fp, "%s", title);
        n = 0;
        for (int i = 0; i < strlen(name1); i++) {
            m = n;
            for (int j = 0; j < strlen(name2); j++) {
                if (name1[i] == name2[j]) {
                    n++;
                    break;
                }
            }
            if (n == m) {
                n = 0;
                break;
            }
        }
        if (n > 0) {
            printf("标题:");
            printf("%s  ", title);
            printf("作者:");
            printf("%s\n", name2);
            fscanf(fp,"%s",cont);
            printf("  %s\n",cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
                printf("  %s\n", cont);
            }
            c++;
            printf("\n");
        } else {
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
            }
        }
    }
    fclose(fp);
    if (c==0) printf ("请更换关键词搜索！！！\n");
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {

        system("cls");
        search1();
    }
}

void search2() {
    FILE *fp;
    system("cls");
    if ((fp = fopen("reply.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        search2();
    }
    printf("请输入回复者：");
    scanf(" %s", name1);
    c=0;
    while (!feof(fp)) {
        fscanf(fp, "%s", title);
        fscanf(fp, "%s", name2);
        n = 0;
        for (int i = 0; i < strlen(name1); i++) {
            m = n;
            for (int j = 0; j < strlen(name2); j++) {
                if (name1[i] == name2[j]) {
                    n++;
                    break;
                }
            }
            if (n == m) {
                n = 0;
                break;
            }
        }
        if (n > 0) {
            printf("回复者者:");
            printf("%s\n", name2);
            fscanf(fp,"%s",cont);
            printf("%s\n",cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
                printf("%s\n", cont);
            }
            c++;
            printf("\n");
        } else {
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
            }
        }
    }
    fclose(fp);
    if (c==0) printf ("请更换关键词搜索！！！\n");
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {
        system("cls");
        search2();
    }
}

void search3() {
    FILE *fp, *fp1;
    system("cls");
    int d=0;
    if ((fp = fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        search3();
    }
    while (!feof(fp)) {
        fscanf(fp, " %s", name2);
        fscanf(fp, " %s", title);
        if (strcmp(name, name2)==0) d++;
        if (!strcmp(name, name2)) {
            printf("标题:");
            printf("%s", title);
            printf("    作者：");
            printf("%s\n", name2);
            fscanf(fp, " %s", cont);
            printf("%s\n", cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, " %s", cont);
                printf("%s\n", cont);
            }
            printf ("\n");
            if ((fp1 = fopen("reply.txt", "a+")) == NULL) {
                printf("打开文件失败\n");
                system("cls");
                fclose(fp);
                system("cls");
                search3();
            }
            while (!feof(fp1)) {
                fscanf(fp1, " %s", title1);
                fscanf(fp1, " %s", name2);
                if (!strcmp(title, title1)) {
                    printf("    回复者：");
                    printf("%s\n", name2);
                    //printf("    回复内容：");
                    fscanf(fp1, "% s", rep);
                    printf("%s\n", rep);
                    while (1) {
                        if (strcmp(rep, "stop") == 0) break;
                        fscanf(fp1, " %s", rep);
                        printf("%s\n", rep);
                    }
                    printf ("\n");
                }
                else {
                    fscanf(fp1, " %s", rep);
                    while (1) {
                        if (strcmp(rep, "stop") == 0) break;
                        fscanf(fp1, " %s", rep);
                    }
                }
            }
        }
        else {
            fscanf(fp, " %s", cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, " %s", cont);
            }
            if (feof(fp)&&d==0) printf("找不到帖子！！！\n");
        }
    }
    fclose(fp);
    fclose(fp1);
    printf("是否返回（y or n):");
    scanf(" %c", &b);
    if (b == 'y') {
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {
        system("cls");
        search3();
    }
}

void search4() {
    FILE *fp;
    system("cls");
    if ((fp = fopen("reply.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        search2();
    }
    printf("请输入帖子：");
    scanf(" %s", title);
    c=0;
    while (!feof(fp)) {
        fscanf(fp, "%s", title1);
        fscanf(fp, "%s", name2);
        n = 0;
        for (int i = 0; i < strlen(title); i++) {
            m = n;
            for (int j = 0; j < strlen(title1); j++) {
                if (title[i] == title1[j]) {
                    n++;
                    break;
                }
            }
            if (n == m) {
                n = 0;
                break;
            }
        }
        if (n > 0) {
            printf("帖子标题：");
            printf("%s\n", title1);
            printf("回复者者:");
            printf("%s\n", name2);
            fscanf(fp,"%s",cont);
            printf("%s\n",cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
                printf("%s\n", cont);
            }
            c++;
            printf("\n");
        }
        else {
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
            }
        }
    }
    fclose(fp);
    if (c==0) printf ("请更换关键词搜索！！！\n");
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        if (strcmp(name,"visitor")==0)
            menu21();
        else menu2();
    }
    else {
        system("cls");
        search2();
    }
}

void reply(){
    FILE *fp1;
    for (int i = 0; i <= 125; i++) {
        rep[i] = '\0';
    }
    if ((fp1= fopen("reply.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        reply();
    }
    fprintf(fp1,"%25s ",title);
    fprintf(fp1,"%10s",name);
    printf("请输入回复内容(输入stop，返回上一级):");
    scanf(" %s",rep);
    if (strcmp(rep, "stop") == 0) {
        system("cls");
        menu3();
    }
    while(rep[125] != '\0') {
            printf("您输入的内容字数超过要求，请重新输入");
            for (int i = 0; i <= 125; i++) {
                rep[i] = '\0';
            }
            scanf(" $s", rep);
    }
    while(100){
        fprintf(fp1," %125s",rep);
        if (strcmp(rep, "stop") == 0) break;
        for (int i = 0; i <= 125; i++) {
            rep[i] = '\0';
        }
        printf("输入完成，则输入stop，输入未完成，则继续输入:");
        scanf(" %s",rep);
        while(rep[125] != '\0'){
                printf("您输入的内容字数超过要求，请重新输入");
                for (int i = 0; i <= 125; i++) {
                    rep[i] = '\0';
                }
                scanf(" $s", rep);
        }
    }
    fprintf(fp1,"\n");
    fclose(fp1);

}

void reply1(){
    FILE *fp;
    if ((fp= fopen("post.txt", "a+")) == NULL) {
        printf("打开文件失败\n");
        reply1();
    }
    for (int i = 0; i <= 25; ++i) { title[i]=' ';}
    for (int i = 0; i <= 10; ++i) { name1[i]=' ';}
    printf("\n请输入想要回复帖子的标题:"); scanf(" %s",title);
    printf("请输入想要回复帖子的作者:"); scanf(" %s",name1);
    while (100) {
        fscanf(fp, " %s %s", name2,title1);
        if (feof(fp)) break;
        if (strcmp(name2, name1) == 0 && strcmp(title, title1) == 0) {
            reply(); fclose(fp);
            system("cls");
            if (strcmp(name,"visitor")==0) menu21();
            else menu2();
        }
        fscanf(fp," %s",cont);
        while(1){
            if (strcmp(cont, "stop") == 0) break;
            fscanf(fp," %s",cont);
        }
    }
    fclose(fp); system("cls");
    if (strcmp(name,"visitor")==0) menu21();
    else menu2();
}

void deletecode(){
    FILE *fp;
    n=0;
    system("cls");
    printf("请输入需修改密码的账号（输入stop，返回上一级）:");
    scanf("%s",name2);
    if(strcmp(name2, "stop")==0){
        system("cls");
        menu();
    }
    if ((fp = fopen("member.txt", "r+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        menu22();
    }
    while (!feof(fp)) {
        fscanf(fp, " %s %s", name1, code1);
        if (feof(fp)) break;
        if (strcmp(name2,name1)==0) {
            n++;
            fseek(fp, -10, SEEK_CUR);
            printf("请输入新密码:");
            scanf(" %s", code);
            for(int i=0;i<=10;i++){
                if(code[i]!='\0'||code[i]!=' ') continue;
                code[i]=' ';
            }
            fprintf(fp, "%10s", code);
            break;
        }
    }
    if (n==0) printf("\n您输入的用户昵称有误！！!\n");
    fclose(fp);
    printf("是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        menu22();
    }
    else {
        system("cls");
        deletecode();
    }
}

void deletepost() {
    FILE *fp;
    for (int i = 0; i<11; i++) {
        name1[i]='\0';
        title[i]='\0';
    }
    for (int i = 11; i <=25; i++) {
        title[i]='\0';
    }
    printf("请输入需删除帖子的标题:");
    scanf(" %s", title);
    printf("请输入需删除帖子的作者:");
    scanf(" %s", name1);
    if ((fp = fopen("post.txt", "r+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        menu22();
    }
    while (100) {
        fscanf(fp, " %s %s", name2,title1);
        if (feof(fp)) break;
        if (strcmp(name2, name1) == 0 && strcmp(title, title1) == 0) {
            fseek(fp, -35, SEEK_CUR);
            name2[0]='\0';
            title1[0]='\0';
            for (int i = 1; i<11; i++) {
                name2[i]='\0';
                title1[i]='\0';
            }
            for (int i = 11; i <=25; i++) {
                title1[i]='\0';
            }
            fprintf (fp,"%10s %25s",name2,title1);
            fscanf(fp, "%s", cont);
            while (100) {
                printf("%s\n",cont);
                if(strcmp(cont, "stop")==0){
                    fseek(fp, -125, SEEK_CUR);
                    cont[0]='\0'; cont[1]='\0';
                    for (int i = 2; i <= 125; i++) {
                        cont[i]='\0';
                    }
                    fprintf(fp,"%125s",cont);
                    break;
                }
                fseek(fp, -125, SEEK_CUR);
                cont[0]='\0'; cont[1]='\0';
                for (int i = 2; i <= 125; i++) {
                    cont[i]='\0';
                }
                fprintf(fp,"%125s",cont);
                fscanf(fp, " %s", cont);
                if (feof(fp)) break;
            }
            //fprintf(fp,"\n");
//            fclose(fp);
//            printf("是否返回（y or n):");
//            scanf(" %c", &b);
//            if (b == 'y') {
//                system("cls");
//                menu22();
//            } else {
//                system("cls");
//                deletepost();
//            }
        }
        else {
            fscanf(fp, "%s", cont);
            while (1) {
                if (strcmp(cont, "stop") == 0) break;
                fscanf(fp, "%s", cont);
            }
        }
    }
    if (!(strcmp(name2, name1) == 0 && strcmp(title, title1) == 0)){
        system("cls");
        printf ("信息有误，请重新输入！！！");
        fclose(fp);
        deletepost();
    }
    fclose(fp);
    printf("是否返回（y or n):");
    scanf(" %c", &b);
    if (b == 'y') {
        system("cls");
        menu22();
    } else {
        system("cls");
        deletepost();
    }
}

void adminshow(){
    FILE *fp;
    if ((fp = fopen("member.txt", "r+")) == NULL) {
        printf("打开文件失败\n");
        system("cls");
        menu22();
    }
    printf("账号:");
    printf("      密码:\n");
    while(100){
        fscanf(fp,"%10s %10s",name1,code1);
        if (feof(fp)) break;
        printf("%-10s %-10s\n",name1,code1);
    }
    fclose(fp);
    printf("\n是否返回（y or n):");
    scanf(" %c",&b);
    if (b=='y'){
        system("cls");
        menu22();
    }
    else {
        system("cls");
        adminshow();
    }
}

int main() {
    menu();
    return 0;
}
