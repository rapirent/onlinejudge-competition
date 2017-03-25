# code
## uva
- 10392:質數(素數)
    - 建表完成, 選擇使用6n+-1法, 並配合vector, 如此才能少用空間

- 10311:質數(素數)
    - 找一個數是否能被分為兩個質數, 若可以則印出差距最小的一組質數, 必須要一大一小
    - 思維:
        - 除了2以外的質數都是奇數, 所以一個奇數輸入如果可以拆分, 必定有一個2
            - 這是因為奇數-奇數=偶數
        - 而如果輸入為偶數, 則必須不斷窮舉, 因為可以除二(必定一大一小或是兩個質數相加)來限制
    - 如果使用建表刪去法的話, bool陣列記得不可寫==1 ==0（我也不知道為什麼）
    - 如果使用memset來做陣列清理的話, int陣列不可以寫memset(array,1,sizeof(array)), 這會讓array element = 16XXX (應該是short的上界) 只有bool 陣列才會全為true(有值就是ture)
    - 建表法建到100000000都可以 超神奇 讚讚讚

- 375:浮點數運算
    - 找到兩個三角形的比例, 算出高, 每次更新這個比例
    - 不用引入eps 但不知道為什麼
    - 可以使用puts("")來印出新行
    - printf("%13.6lf\n",input)的\n必須加上去, 這樣才不會有遺留符號%
- 11408:質數、建表
    - 使用精不可妙的篩法找出dePrime 有夠猛
    - 注意題目的輸出範圍為5000000, 我設1000000而吃了一個runtime error, 而且run time = 0.0

- 10407:gcd
    - 題目雖然是找某個除數使被除數運算後同餘, 但其實兩數相減後, 相同餘數會被消去, 所以可以知道得找gcd
    - n1 = x1*q1 + r1
    - n2 = x1*q2 + r1
    - n3 = x1*q3 + r1
    - 相減得到 a1 = n1 - n2 = x1*(q1-q2), a2 = n1 - n3 = x1*(q1 - q3)
    - 而如果只有兩個數, 則有x1*(q1 - q2) = (n1 - n2)*1, 故兩數相差即此數!!!!!
- 532:BFS
    - 就是簡單的BFS, 運用C++的queue搭配struct可以簡單完成
    - 重點是重置array, 多維可以使用memset(array, 0, sizeof(array[0][0])*m*n)
    - c++11才支援queue.push(node{1,1})，一般使用node p = {1,1}; queue.push(p)
    - queue要記得清空喔!!
- 10090:GCD
    - 使用擴充輾轉來解不定方程, 如果指定輸入不是gcd的倍數的話則此不定方程無解
    - 題目要求找到n1*x+n2*y = marble的解, 並讓其滿足c1*x+c2*y最小
    - n1*x' +n2*y' = gcd , n1*(x*marble/gcd) + n2*(y*marble/gcd) = gcd*marble/gcd = marble
    - n1*x + n2*y = marble
    - m1 = m1 + n2 / g * t  , m2 = m2 –  n1 / g * t 
    - x'' = x + n2 / gcd *t, y'' = y - n1 / gcd *t ''代表最終決定值
    - cost = c1* x'' + c2 * y'' = c1*(x + n2/gcd*t) + c2*(y - n1/gcd*t)
            = (c1*x+c2*y)+(c1*n2 - c2*n1)/gcd*t
- 10606:大數
    - 因為太麻煩了所以拿java來寫..只是java有很多限制讓我吃了兩個compilation error
        - 不能有public class, 檔名得寫Main, 進入點Class得寫Main
    - 參考陳鐘誠的電腦二元逼近法
- 11538:數學
    - 因為結果可能會超出2147483647, 得用long long int來存
    - 朱世傑恆等
- 10035:數學
    - 使用sprintf計算進位運算個數即可, 記得就算單一位無進位, 只要加上carry還有進位就算
- 167:八皇后、回朔、backtracking
    - 使用一個長度為八的陣列來儲存第x行的第y列該放置皇后, 而因為八皇后的答案有92個, 所以使用vector來儲存
        - 不要使用全域變數搭配陣列, 因為遞迴backtracking在遍尋第一個答案後更新count, 將會使下一個答案紀錄錯誤
        - 除非可以每次答案返回後將原本已經給出的count都加1
- 906:float number、浮點數
    - 題意: 0 < c/d - a/b <= n, 給定a,b,n找出c/d 
    - 千萬不能夠單純的c=a/b*d,需要while(a*d>=c*b) c++;來找出真正c值
- 10341:解方程式
    - 使用牛頓法
    - 注意精度、underflow(引入eps)
    - 有第二種方法, 使用binary search
- 674:coin change、DE
    - 無限可能的coin change 問題
- 200:DAG、topological sort
    - 使用陣列來實做比較簡單
    - 有20個輸入, 用fgets記得要設成21
    - 當只輸入一個單字時就輸出該個單字
## POJ

- 2533:LIS
    - 算出LIS就好了
