

package com.sf.ccmas.video.config.odd.od10;

import java.util.*;

/**
 * 分界线
 * 时间限制:1s 空间限制: 32MB 限定语言:不限题目描述:
 * 电视剧《分界线》里面有一个片段，男主为了向警察透露案件细节，
 * 且不暴露自己，于是将报刊上的字剪切下来，剪拼成匿名信。现在有一名举报人，希望借鉴这种手段，使用英文报刊完成举报操作。
 * 但为了增加文章的混淆度，只需满足每个单词中字母数量一致即可，不关注每个字母的顺序解释:单词on允许通过单词'no'进行替代
 * 报纸代表newspaper，匿名信代表anonymousLetter,求报纸内容是否可以拼成匿名信
 *
 *
 *
 * 输入描述:
 * 第一行输入newspaper内容，包括1-N个字符串，用空格分开
 * 第二行输入anonymousLetter内容，包括1-N个字符串，用空格分开
 * 1、newspaper和anonymousLetter的字符串由小写英文字母组成且每个字母只能使用一次
 * 2、newspaper内容中的每个字符串字母顺序可以任意调整,但必须保证字符串的完整性(每个字符串不能有多余字母)
 * 3、1<N<100 , 1<= newspaper.length, anonymousLetter.length <= 104
 * 输出描述:
 * 如果报纸可以拼成匿名信返回ture，否则返回false
 *
 * 示例1
 *
 * 输入:
 * ab cd
 * ab
 *
 * 输出:
 * true
 *
 * 示例2
 *
 * 输入:
 * ab ef
 * aef
 *
 * 输出:
 * false
 *
 *
 * 示例3
 *
 * 输入:
 *
 * ab bcd ef
 * cbd fe
 *
 * 输出:
 * true
 *
 * 示例4
 *
 * 输入:
 * ab bcd ef
 * cd ef
 * 输出:
 * false
 *
 */


//本题通过递归的方式来解决

/**
 * 关联端口组合并
 * 时间限制:1s空间限制: 256MB 限定语言:不限
 * 题目描述:
 * 有M (1<=M<=10)个端口组，每个端口组是长度为N(1<=N<=100)的整数数组，如果端口组间存在2个及以上不同端口相同，则认为这两个端口组互相关联，可以合并。第一行输入端口组个数M，再输入M行，每行逗号分隔，代表端口组，输出合并后的端口组用二维数组表示
 */
public class Main {
    public static void main(String[] args) {
//        int n = 5;
//        Double pow = Math.pow(2, n);
//        //取整数值
//        long round = Math.round(pow);
//        System.out.println(pow.intValue());

        Scanner scanner = new Scanner(System.in);
        String newspaper = scanner.nextLine();
        String anonymous = scanner.nextLine();
        String[] newspaperArray = newspaper.split(" ");
        String[] anonymousArray = anonymous.split(" ");
        Set<String> set = new HashSet<>();
        for (String news : newspaperArray) {
            char[] charArray = news.toCharArray();
            Arrays.sort(charArray);
            String value = String.valueOf(charArray);
            set.add(value);
        }
        boolean canAppend = true;
        for (String anonymousStr : anonymousArray) {
            char[]  anonymousCharArray = anonymousStr.toCharArray();
            Arrays.sort(anonymousCharArray);
            String sortedAnonymous = String.valueOf(anonymousCharArray);
            //如果有匿名的，在set里没有对应上，说明无法拼出，返回false
            if (!set.contains(sortedAnonymous)) {
                canAppend = false;
                break;
            }
        }
        if (canAppend) {
            System.out.println("true");
        }else {
            System.out.println("false");
        }
    }
}
