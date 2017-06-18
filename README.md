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
    - 1000\*1000\*1000 = 1000000000 大概一兩秒而已
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
- 902:trie
    - 就是使用trie儲存結果, 接著以backtracking做遍尋, 以全域變數儲存最大的word count, 假如trie的字母數量大於此word count則把它儲存到結果字串中, 當backtracking結束後印出結果字串即可
    - ..我的電腦上執行會core dump...但uva卻accept(邊界太大)
        - 但是如果把邊界設小..我的電腦雖然能執行但uva卻runtime error = =
- 341:bellman-ford
    - 單純的bellman-ford, 不過要做字串處理(strtok), 而且還要使用stack
- 10000:bellman-ford
    - 把單源最短路徑(single source shortest path)問題換成單源最長路徑問題
- 10048:floyd
    - 修改floyd成紀錄經過路徑中單一最大的分貝數(權重)
    - 最後一個輸出不需要空一行
- 10986:SPFA
    - 記住只有在找到鬆弛後可以加入的邊時才能夠把邊加入queue
        - 吃了七次TLE...
        - 也就是判斷鬆弛條件的if必須包住該邊是否在queue中的if
- 315:component、articulation
    - 直接套用Articulation的模板即可
    - 這題....中間輸入的邊敘述不一定只有N個, 喵的題目騙我
- 459:字串處理、disjoint set
    - ...重點就是字串處理...以後都用gets或fgets讀進來處理!!!
- 10199:字串處理、articulation
    - 善用map，將string轉成index再轉回string
    - sort(vector.begin(),vector.end())
- 247:kosaraju
    - 套用kosaraju的模板
    - 善用map，將string轉成index再轉回string
    - 字典序不重要
- 11504:kosaraju
    - 套用kosaraju模板
    - 使用vector，倒轉時還是使用
- 11709:kosaraju
    - 如果使用adjancy list來存邊，可以另外加入reverse adjancy list來存顛倒邊
    - ...這題因為我沒考慮到可能第一個輸入有可能p或t為0而吃了十幾個WA
- 10765:kosaraju
    - poj1523的變形，求articulation拿掉後可以產生的最大元件數，並且輸出好幾種選擇
    - 每個輸出完都要放一個空行, 吃了一次PE
- 610:bridge
    - 套用模組，以low和dfn來算出bridge
    - 找到bridge後把此bridge當作雙向邊加入答案，並於邊集合中去掉，再行一次dfs拜訪，紀錄拜訪的邊並加入此單向邊（也要去掉此邊代表的雙向邊於集合）
    - 範例輸出的dfs順序不需要全照...只要題意符合即可
- 796:bridge
    - 套用bridge模板
    - 這題一直WA..原來是struct 的sort沒寫好，當from的點相等時要比較to的點
    ```
    bool operator< (const node& a) const {
        if(from==a.from) {
            return to<a.to;
        }
        return from<a.from;
    }
    ```
- 11838:scc、kosaraju
    - 套用kosaraju模板，如果只找到一個scc，那麼就是連通圖!（輸出1）
        - 沒有的話就是錯（輸出0）
- 12783:bridge
    - 套用bridge模板和struct 的sort
- 11770:scc、kosaraju
    - 同poj2553，這次是找入度為0的SCC
    - 題目太大，改用adjancy list
- 10034:MST、kruskal
    - 先存下每個點，再算出每個點和其他點之間的所有邊，加入edge陣列中排序，再從最小者到最大者使用kruskal
- 10369:MST、kruskal
    - 找出MST中第S長的邊即可
- 11597:MST
    - 一個complete graph有n*(n-1)/2個邊(n個點)，而spanning tree最少需要(n-1)個邊，所以最多有n/2個spanning tree
- 10147:MST、kruskal
    - 就是poj1751
- 10397:MST、kruskal
    - uva10147的變形，這次印出的不是所有後來建好路的邊的兩點，而是後來建好的路總長
- 10842:MST、kruskal
    - 套用kruskal模板，只是找maximum spanning tree
- 820:max-flow、Edmons-Karp
    - 套用edmons-karp模板，找出最大流流量
    - 須注意這題兩點之間有多個邊，需要將其全部合併成單一邊...吃了兩個WA
- 10779:max-flow、Edmons-karp
    - 將流視為一次貼紙的交換
    - 所以除了源點(bob)外，其他人如果對於某j種貼紙有多於一張，則有一條至此j點的路徑，其權重為此人擁有此j種貼紙的個數減一
    - 又除了源點(bob)外，其他人j如果沒有該i種貼紙，則有一條i至j的路徑，其權重為1，代表最多只會交換給它一次
    - 又所有貼紙節點都由一個獨立的匯點(自己設的)有一條權重為1的邊，讓最大流代表有多少個這些邊流通（代表源點可以通過此邊到匯點，也就是擁有該種貼紙）
- 10330:max-flow、Edmons-Karp
    - 按照題目的意思建圖，但是將點拆開成邊以表示此點的容量（邊的容量為原本的點的容量）
    - 接著進行Edmons-karp即可
    - 各個點的連接邊需以拆開後邊的結束點為起點，以拆開後邊的開始點為終點
        - 因為這樣才算走過該點，消耗了該點的容量
- 10080:bipartite graph matching
    - 將能在時限內到達的洞和土撥鼠連接，做二分圖最大匹配，再將土撥鼠數量減去最大匹配數即為答案
- 11138:bipartite graph matching
    - 題目會輸入bolts、nuts，輸出他們之間（二分圖）的最大匹配
- 1194:bipartite graph matching
    - 跳過node0，計算除了node0外的二分最大匹配數即可
- 11601:binary indexed tree
    - 使用二維binary indexed tree（其實也可以暴力直接拿陣列存）
    - 直接使用模板（不過演算法筆記的模板我看不太懂他的位元運算），記得計算面積時左下角到右上角其中一方需要減一
- 191:Computational-Geometry
    - 套intersection模板，不過不要使用投影片教的判斷共線法，使用演算法筆記上的投影法
    - 卡超久= =
- 218:Computational-geometry
    - 直接套Andrew’s Monotone Chain模組
    - 但演算法筆記的模板需要修正，因為是當cross product >=02的時候才要修正
- 10902:Computational-geometry
    - 直接套intersection的投影法模板
    - 先讀入所有的線段，然後兩層for迴圈將一個線段和其他者比較，如果沒有重疊則加入答案
    - morris解這題時直接一邊讀入一邊修正已經讀入的數據, 猛= =
- 596:Computational-geometry
    - = =他的sample啥鬼的那串是要直接複製它輸入的！！！！！
    - 其餘直接以Andrew's Monotone chain模板做即可
    - 記得他的輸出格式要x優先，y其次，最後印出剩下的
- 681:Computational-geometry
    - 套用Andrew's Monotone chain即可
    - 我把while寫成if而de了四五個小時..
- 675:Computational-geometry
    - 套用Andrew's Monotone chain即可
    - 但是要將原本輸入的座標點全部紀錄下來，並且在套用monotone chain後和結果互相比較，找到第一個進入Convex Hull者作輸出，接著依序輸出，輸出到底時從頭開始
    - 我把while寫成if而de了五六個小時...
- 11626:Computational-geometry
    - Andrew's monotone chain
    - 忽略共線(==0)
    - 排序先排x座標，再排y
- 100:math
    - 記得輸入的兩個數字可能是先大後小
- 11462:sort
    - 直接拿algorithm中的sort即可解決
- 10583:disjoint-set
    - 直接套用disjoint-set模板即可
- 10078:computational-geometry
    - 原本要直接套用andrew's monotone chain來比對(假如找到凸包中的點數量一樣則對)
    - 但一直錯，就直接比對所有的外積是否一致大於零或小於零
- 10065:computational-geometry
    - 直接套用andrew's monotone chain
    - 除此之外，還要計算原本的多邊形和凸包的面積，在此可以直接計算各點的外積相加除二即可（但起點座標記得要一樣）
    - 計算多邊形和凸包的比例（就是多邊形少了多少比例的面積）
- 11069:dynamic-programming
    - 由於一個集合一定是透過前二和前三個狀態而來（加上目前這個數字而成新的子集合），所以計算n[i] = n[i-2] + n[i-3]即可
    - n[1] = 1、n[2] = 2、n[3] = 2
- 10934:dynamic-programming
    - 樓層可能為零= =，所以只要判斷水球數量是否為0代表終止就好
    - 其實這題我看不太懂..參考網路上而解的，首先我們要求的是「最糟狀態」要試幾次才知道水球在第幾層開始會破掉
    - 因為是「開始破掉」，所以由第0層開始，陣列每個元素都初始化為0
    - 再來，以i代表第i顆水球，j代表嘗試第j次，元素\[i\]\[j\]代表當前可以確定的層數，
        - 而此值為\[i-1\]\[j-1\] +1（水球在上一次嘗試中破掉了，所以換新的，而因為他破掉了代表已經知道一層樓，加一）加上\[i\]\[j-1\]（水球在上一次嘗試還沒破掉，所以不換新
    - 看不懂其中一個對岸寫的解答：http://blog.csdn.net/shuangde800/article/details/11273123
- 10220:dynamic-programming、big-number
    - 大數運算加上以陣列紀錄下當前的結果，並另開一個陣列計算總和
- 10685:disjoint-set
    - 套用disjoint-set模板，加上map來將string轉成對應的index，只是注意有可能union兩個原本就在同個set中的元素！
        - 所以得判斷是不是同一個set，不是才union
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
- 2406:KMP、字串比對、string matching
    - 就是uva10298, 完全一樣
- 2185:KMP、字串比對
    - 我de了8個小時, 就為了index前後顛倒 喵的咧
    - 簡單就是做KMP, 找出row和col的最小重複字串長度的公倍數
    - 大陸好像都是用別的寫法寫KMP, 使之最後再一個元素儲存pi[最後元素]加一
    - 真的怒火衝天 森77
- 1125:floyd
    - 就是floyd
    - **問題:為什麼不能使用-1作為inf?**
- 1724:bellman-ford、SPFA
    - 使用priority queue來得到花費最小, 每次加入一條不會造成花費超過的點
    - 類似SPFA, 但比較多BFS
    - **SPFA的觀念(BFS)還不太懂 要問**
- 2387:bellman-ford
    - 就是bellman-ford找有無無限環
- 1523:articulation
    - 直接套用articulation的模板，只是這次再找到articulation的同時，將拜訪此articulation的次數紀錄起來，即為拿掉articulation後的元件數
- 2117:articulation
    - 1523的延伸，因為一開始圖有可能就是不連通得，所以結果為「一開始的連通圖數量+拿掉articulation後的最大元件數-1」
    - 要考慮c==0的情況
- 2553:kosaraju、scc
    - 找出度為0的SCC（其實這題我看不太懂...看網路上別人提醒要找出度為0才理解)
    - 基本上可以使用kosaraju找出所有SCC，再以三層for迴圈（因為我是用adjancy matrix）進行每個邊的迭代測試，剔除有指向其他SCC的SCC
        - 非常慢，但反正AC了
- 2186:kosaraju、SCC
    - 和2553一樣，找出度為0的SCC中的點個數，注意只能有一個，如果有超過兩個出度為0的SCC則輸出0
- 1861:MST、kruskal
    - 就是kruskal模板
- 2395:MST、kruskal
    - 就是kruskal模板...只要印出最後一個進入kruskal的MST之邊的邊長即可
- 2421:MST、kruskal
    - 就是kruskal模板，只是這次將已經蓋好的路的長度標為0，使它一定被加入MST
- 1751:MST、kruskal
    - 跟2421很像, 就是kruskal模板，已經蓋好的路長度標為0
    - 輸出不用照順序
    - pow的第一個參數記得引入(double)，否則會有像是pow(9,9)的錯誤
        - pow(int, int)在math.h中被刪除(removed from math.h in the CRT)
- 2560:MST、kruskal
    - 跟uva10034一模一樣
        - 除了不用開頭要求有幾個輸入
- 2485:MST、kruskal
    - 就是2421....
    - 但改為先輸入會有幾次輸入，並且輸出MST中最大的邊長
- 1258:MST、kruskal
    - 套用kruskal模板，再讀取adjancy matrix時轉為模板中的邊
- 2377:MST、kruskal
    - kruskal，只是這次條件為掃過全部邊，看加入的集合中是否只有n-1個元素(邊)
    - 如果是，則印出邊價格總和
    - 如果不是則印出-1
- 3625:MST、kruskal
    - 將已經存在的點union起來，最後掃過所有的邊，看是否能加入kruskal，有則加入，並且加總其長度
- 2455:max-flow、edmons-karp
    - 以二分搜尋找出constrain，再以此constrain訂出一張圖之capacity，進行max_flow查找
        - 找出這些最大流流量的上界
    - 查找後確認是否可以找到T條流，如果可以，則印出此上界
- 2584:max-flow、edmons-karp
    - 將每個人設為節點，而源點和這些點都有一條權重為1的道路
    - 再將衣服設為節點，而與該人合身的衣服節點和該人都有一條權重為1的道路相連
    - 最後，每個衣服節點和匯點都有一條以數量為權重的道路
    - 只要最大流等於人數即可!!
- 2536:bipartite graph matching
    - 跟uva 10080一模一樣 
- 1325:bipartite graph matching
    - 跟uva 1194一模一樣
- 2352:binary indexed tree
    - 模板+另外建一紀錄當前總數的陣列，每次更新
- 3468:binary indexed tree
    - 模板可解，但會超時，因為他的modify太多次了
    - 網路上有人直接歸納出公式解，以兩個binary indexed陣列維護
- 3067:binary indexed tree
    - 題目大意： 順序給兩組平行的點依次編號1~N和1~M，給定K個線段在兩組點之間，求相交(cross)的線段對有多少個，同一個起點或終點不算相交
    - 題目分析：把N從大到小排序，注意：當N相等的時候按M的從大到到小！因為我們計算的時候，求N點構成的交點的個數隻需要遍歷他前面的點對，因為他前面的點對的N值肯定比他大，所以只要M的值比他小肯定就構成了1個交點，所以轉換為計算比當前值小的數的個數！這就是樹狀數組的真諦！然後如果當N相等的時候時候，如果把M小的放前面，計算他後面那個N值相等的點的時候，前面M比他小錯誤的加上了1，所以當N相等的時候必須按M從大到小的安放！
    - http://xuyemin520.is-programmer.com/posts/26032.html
- 1195:binary indexed tree
    - 二維binary indexed tree題目
    - 記得index要從1開始阿...不然會無窮迴圈, 所以呼叫模板時要加1
    - 陣列要開大...我開剛剛好(1024)結果吃了兩個WA
- 2155:binary indexed tree
    - 其實不太懂，不過就是把二維binary indexed tree的模組修改，使之儲存的為0和1，做的運算為和1^（not）
- 1000:math
    - 直接印出輸入的a b之a+b即可
- 1004:math
    - 直接印出十二個數的平均即可
- 1298:string
    - 後退五位（不是前進五位），而A～E則要後退四位再前進90位
    - 為了strcmp搞了很久，應該判斷到\0，所以改用strncmp
- 1450:math
    - 如果輸入n、m都是奇數，則輸出n*m+1.414 - 1
    - 如果不是則輸出n*m
    - 需要轉型成double!
    - 其實我懶的看題目...看網路上別人推的結論解的
## ICPC
- 4262:SCC、kosaraju
    - 就是kosaraju，記得使用vector作為topo order時，最後一個index為topo.size()-1
