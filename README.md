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
- 574:backtracking
    - 因為輸入陣列已經排序, 直接由大而小開始backtracking即可
    - 注意我們得去除重複的答案, 我使用的方法是保證輸入答案都是遞減的, 出現遞增的時候即剪枝
    - 不要在最後才剪除(以for迴圈全部走訪答案陣列), 會TLE
- 624:0/1背包問題、knapsack problem、DP
    - 把它當作0/1背包問題即可, 只是走訪得出答案有點困難...
- 989:backtracking
    - 使用index即可, 因為matrix本身就會紀錄行、列、九宮格
        - 這邊有點難想
    - 每個輸出資料間都要空一行, 所以除了第一個資料外, 一開始都輸出一個空白行, (吃了一個PE)
- 11085:backtracking、八皇后
    - 是167的改進, 首先要計算出所有92種答案組合, 在和輸入做比較
    - 需要注意, 輸入的y座標是由1開始, 所以一開始窮舉答案的時候都得從1開始算答案座標
        - 不過不懂為什麼不能直接比較的時候減一就是了...
- 990:DP、knapsack、背包問題
    - 就背包問題
    - 可是我隨便用queue解就過了...真怪, 但udebug上卻沒過
- 10819:背包問題、DP
    - 直接當作只有一枚硬幣的換錢問題即可
    - 只是有小bug但卻過了...
- 10898:背包問題、DP
    - 有些小錯, 不過應該是超出integer範圍(都設成1e9了...)的關係, 動態規劃的記憶體處理很重要阿...
    - 直接把一般餐點當作一份組合餐來看待(只是只有某一份餐點而已), 接著以DP搜尋這些組合餐可以使得花費最小者
- 11407:DP、背包問題、coin change
    - 簡單就是無限硬幣換錢問題
    - 只是轉換為, 一開始全都為0, 只要目前遍尋的答案(index)不為0, 則找出可能的最小答案
    - 如果為0, 則觀察是否可由減去一個小於此index的平方數得到答案(判斷index減去平方數的元素是否不為0)
        - 如果有則令目前的元素為該index減去平方數的元素加一
        - 有例外狀況, 如果index減去平方數為0, 因為dp[0]=0為正確答案, 所以通過
    - morris大神有另一個更神的算法:所有元素都為無限大(可以設為index上限), 並且每次找尋可能的最小值
        - 因為不會和dp[0]碰撞, 可以利用!!!(碰到dp[0]都是dp[0] + 1和其他者相比較, 當然dp[0] + 1 會勝出)
            - 就是該index是否可以被一個平方數替代
        - 不過必須要先有dp[1]
- 103:LIS
    - 把LIS的想法轉為題目中的contain box即可, 非常簡單
    - 記得將上一個index留下, 從而以stack(function call)的方式從最後一個index走訪
- 437:LIS
    - 把LIS轉為長和寬, 並且如果可以容納, 就加上該積木的高
        - 原本LIS算法中每個元素初始為1(因為自己都是一個LIS)被換成該積木最多可以疊多少
- 231:LIS
    - 倒著做LIS即可(題目是一個系統雖然可以無限高的攔截飛彈, 但一次只能攔截比上一次低的飛彈, 求最高可以攔截多少顆)
- 111:LCS
    - 這題只會有一組測資!!!!因為它分辨不出來!!!
        - 想超久到底有沒有第二組測資QQ
    - 將第二行輸入(標準答案)和每個學生的答案(第三行開始的輸入)做LCS比較並算出最大的LCS長度即可
- 481:LIS
    - 使用O(nlgn)的方法做(binary search建stack)
    - **不過搞不清楚為什麼不能直接拿建好的stack來印出, 還得自己遍尋一次**
        - 因為題目要求最後出現, 節省時間的方法是從input元素陣列的最後面向前走訪, 比較index, 推入queue, 再依序印出queue
- 10066:LCS
    - 就是做LCS
    - LCS必須注意, 三個陣列(LCS、字串a和字串b)的第一個元素(或第一列、第一行元素)都是0, 須空出來, 這樣index才會對齊
    - 這題每個測資都要空一行...不是最後一個不用空, 害我吃了一個PE
- 10131:LIS
    - 難在排序和搞清楚題目的輸入順序
    - 以後做這種題目都先建struct
- 10405:LCS
    - 就是簡單的LCS...
    - 要小心當輸入兩個空白行時, 應該輸出0, 這時兩個輸入列(如果使用fgets)的長度都是1(而不是0, 因為有'\n')
- 10192:LCS
    - 就是簡單的LCS...
    - 要注意的是連只有一個city的輸出都要寫cities(沒有特例!)
- 10611:binary search、二分查找、二分搜尋
    - 就是對輸入陣列排序後做二分搜尋
    - 不過記得輸入陣列的元素有可能重複, 所以如果有找到, 記得以while迴圈往左或往右數直到不是重複的該元素
- 714:binary search、greedy
    - 重點是從{所有元素的最大值~所有元素總和值}找到我們要的「臨界值」, 讓這個臨界值最小但又夠大容納所有分割中的元素總和
        - 詳細的作法是嘗試上述集合的每一個可能, 但為了讓查找快速, 我們使用binary search輔助!!!
    - 但題目還有一點, 希望讓最後一個partition的人拿到盡量多的, 所以我們遍尋元素陣列時, 是從後面往前遍尋, 並且比對是否使用剛剛找到的臨界值劃分後的分割數大於應有的劃分, 如果是, 則將遍尋到的元素納入partition中
    - **不過不太懂為什麼不用sort**
        - 這是因為題目的secriber不是按照從左到右的順序排的, 所以不需要排列
        - 詳情請看第一個範例輸出
- 11413:binary search
    - 同714, 不過比較簡單, 不需要考慮greedy, 只是單純求劃分的最大值
    - 就是使用binary search從{所有元素的最大值~所有元素總和值}中找到劃分集合的總和臨界值
- 10100:LCS
    - 重點是要怎麼分割字串, c++的isstream和c的strtok
- 455:字串比對
    - 不需要KMP, Z或其他演算法, 只需要以三層迴圈測出period即可
    - 1000*1000*1000 = 1000000000 大概一兩秒而已
- 10298:字串比對
    - 跟455很像, 都是找週期, 所以可以使用455的方法
    - 不過也能使用KMP的fail function, 因為fail function就是在找pattern的重複部份, 使之在字串比對時能夠忽略已經比過的重複的部份!(KMP的本質即為B中有重複的部份, 不用比, 如果能確定之前的已經比對完成, 那A可以直接跳過之後重複的部份不比)
        - 但也是因為這樣, 假如pattern中沒以重複的部份, 則演算法時間會退化到O(|A||B|)
    - 總之就是找到重複的長度, 再由總長度減掉重複的長度, 從而得到最開頭, 之後會重複的週期長度
- 11475:字串比對、KMP
    - 可以使用Z algorithm, 可是會TLE= =
        - Z到底能解什麼題目阿....根本每題都TLE阿
    - 使用KMP比對輸入字串和反轉的輸入字串, 其中反轉的輸入字串當作pattern
        - 找到反轉輸入字串的後綴跟哪些輸入字串的前綴一樣
        - 因為KMP就是在求後面重複的字串長度
## POJ

- 2533:LIS
    - 算出LIS就好了
- 3624:DP、01背包問題
    - 就是很基本的01背包問題
- 2392:DP、有限物品背包問題、有限coin change問題
    - state:c[j] = max(c[j],c[j - h] + h)
        - 其中h為高度
- 1742:DP、有限物品背包問題、有限coin change
    - 這題有時間限制, 如果只是用一般的方法解有限物品問題的話, 會TLE
        - memset也有時間成本, 不是說一行完成...只挑有需要初始化的來使用
    - 以一個num陣列紀錄使用A\[i\](第i個硬幣)的數量, 並且檢查是否可以增加, 能增加則在dp陣列中記錄下來
    - 每次換一種新的硬幣都把num陣列初始化, 這樣就可以避免已經可以湊得者被重複遍尋(10 = 5 + 5 = 2 + 2 + 2 + 2 +2 , 如果2已經遍尋, 則5不必)
    - 網路上說此法greedy, 但我不懂為什麼...
	    - A:因為每次都取最佳, 然後不再取!!
- 1276:DP、有限背包問題
    - 因為時間有限, 使用2^n表示法來壓縮, 並使其成為無限背包
    - **其實還是不太懂**
- 1384:DP、無限背包問題
    - 求最低, 所以我們只要將DP陣列中的值設為最大即可, 然後由0出發
- 1631:LIS
    - 不能使用一般的O(n^2)的演算法, 要使用stack法(O(nlgn))
- 2387:Single-source-shortest path
    - 重點是題目是給無向圖...所以使用bellman-ford得存雙向的邊!!
    - 沒有負邊, 不必處理
- 3259:Single-source-shortest path
    - 重點是題目的理解...
    - 只要起點到終點的路徑上有負向邊, 則對(因為它會一直loop, 遇見之前的自己), 否則錯
- 3461:string matching、字串比對
    - 不知道為什麼, 使用M algorithm會TLE
        - 應該是要把Z陣列初始化的緣故
    - 直接套KMP, 比對成功count++
- 1961:字串比對、string matching、KMP
    - 不多說, 因為KMP就是再找一個字串後面的部份有哪些跟前面重複, 所以我們只要將該數字減掉當前長度, 就可以輕易算出前面重複的字串內容, 再判斷是否可以週期重複(整除總長度)
