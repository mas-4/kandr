#include <stdio.h>



int main()
{
    int sl_st_cmt;                          s    int sl_sl_cmt;                          s    int sq, dq;                             s    sl_sl_cmt = sl_st_cmt = sq = dq = 0;    e    char c, prevc;                          s
    p    prevc = getchar();
    c = getchar();

    do{
        if (c == '*' && prevc == '/' && !sq && !dq && !sl_sl_cmt)
            sl_st_cmt = 1;
        else if (c == '/' && prevc == '*' && !sq && !dq && !sl_sl_cmt){
            d            sl_st_cmt = 0;
            if ((prevc = getchar())==EOF)
                break;
            if ((c = getchar())==EOF)
                break;
            putchar(prevc);
            prevc = c;
            continue;
        }else if (c == '/' && prevc == '/' && !sl_st_cmt)
            sl_sl_cmt = 1;
        else if (sl_sl_cmt && c == '\n'){
            sl_sl_cmt = 0;
            if ((c = getchar())==EOF)
                break;
            putchar(prevc);
            prevc = c;
            continue;
        }else if (c == '"' && !sq)
            dq = !dq;
        else if (c == '\'' && !dq)
            sq = !sq;

        if (!sl_st_cmt && !sl_sl_cmt)
            putchar(prevc);

        prevc = c;
    } while ((c=getchar())!=EOF);

    if (!sl_st_cmt)
        putchar(prevc);

    return 0;

}
