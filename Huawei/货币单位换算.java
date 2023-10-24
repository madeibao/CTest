
package com.sf.ccmas.video.config.odd.od12;

import java.util.*;


/**
 * 货币单位换算
 * 时间限制:1s空间限制: 256MB 限定语言:不限
 * 题目描述:
 * 记账本上记录了若干条多国货币金额，需要转换成人民币分 (fen)，汇总后输出。
 * 每行记录一条金额，金额带有货币单位，格式为数字+单位，可能是单独元，或者单独分，或者元与分的组合。
 * 要求将这些货币全部换算成人民币分 (fen)后进行汇总，汇总结果仅保留整数，小数部分舍弃。
 * 元和分的换算关系都是1:100，如下:
 * 1CNY=100fen (1元=100分)
 * 1HKD=100cents (1港元=100港分)
 * 1JPY=100sen (1日元=100仙)
 * 1EUR=100eurocents (1欧元=100欧分)
 * 1GBP=100pence(1英镑=100便士)
 * <p>
 * 汇率如下表
 * CNY  JPY    HKD   EUR  GBP
 * 100  1825   123   14    12
 * <p>
 * 即100CNY=1825JPY=123HKD=14EUR=12GBP
 * <p>
 * <p>
 * 输入描述:
 * 第一行输入为N，N表示记录数。0<N<100之后N行，每行表示一条货币记录，且该行只会是一种货币输出描述:
 * 将每行货币转换成人民币分 (fen) 后汇总求和，只保留整数部分。
 * 输出格式只有整数数字，不带小数，不带单位
 * 补充说明:
 * 输出格式只有数字，不带单位
 * <p>
 * 示例1
 * 输入:
 * 1
 * 100CNY
 * 输出:
 * <p>
 * 10000
 * 说明:
 * 100CNY转换后是10000fen，所以输出结果为10000
 * <p>
 * 示例2
 * 输入:
 * 1
 * 3000fen
 * 输出:
 * 3000
 * 说明:
 * 3000fen，结果就是3000
 * <p>
 * <p>
 * 示例3
 * 输入:
 * 1
 * 123HKD
 * 输出:
 * 10000
 * 说明:
 * HKD与CNY的汇率关系是123:100，所以换算后，输出结果为10000
 * 示例4
 * 输入:
 * 2
 * 20CNY53fen
 * 53HKD87cents
 * 输出:
 * 6432
 * 说明:
 * 20元53分+53港元87港分，换算成人民币分后汇总，为6432
 */
public class Main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String numStr = scanner.nextLine();
        int m = Integer.parseInt(numStr);

        double sum = 0d;
        for (int i = 0; i < m; i++) {
            String line = scanner.nextLine();
            boolean hasCny = line.contains("CNY");
            boolean hasfen = line.contains("fen");
            if (hasCny) {
                String[] strings = line.split("CNY");
                double yuan = Double.parseDouble(strings[0]);
                double fen = 0;
                if (strings.length > 1) {
                    if (strings[1].contains("fen")) {
                        String[] fensStr = strings[1].split("fen");

                        fen = Double.parseDouble(fensStr[0]);
                    }
                }
                double val = yuan * 100 + fen;
                sum += val;
            }

            if (line.contains("JPY")) {
                String[] strings = line.split("JPY");
                double yuan = Double.parseDouble(strings[0]) / 1825 * 100;
                double fen = 0;
                if (strings.length > 1) {
                    if (strings[1].contains("sen")) {
                        String[] fensStrArr = strings[1].split("sen");
                        fen = Double.parseDouble(fensStrArr[0]) / 123 * 100;
                    }
                }
                double val = yuan * 100 + fen;
                sum += val;
            }


            if (line.contains("HKD")) {
                String[] strings = line.split("HKD");
                double yuan = Double.parseDouble(strings[0]) / 123 * 100;
                double fen = 0;
                if (strings.length > 1) {
                    if (strings[1].contains("cents")) {
                        String[] fensStrArr = strings[1].split("cents");
                        fen = Double.parseDouble(fensStrArr[0]) / 123 * 100;
                    }
                }
                double val = yuan * 100 + fen;
                sum += val;
            }

            if (line.contains("EUR")) {
                String[] strings = line.split("EUR");
                double yuan = Double.parseDouble(strings[0]) / 14 * 100;
                double fen = 0;
                if (strings.length > 1) {
                    if (strings[1].contains("eurocents")) {
                        String[] fensStrArr = strings[1].split("eurocents");
                        fen = Double.parseDouble(fensStrArr[0]) / 14 * 100;
                    }
                }
                double val = yuan * 100 + fen;
                sum += val;
            }

            if (line.contains("GBP")) {
                String[] strings = line.split("GBP");
                double yuan = Double.parseDouble(strings[0]) / 123 * 100;
                double fen = 0;
                if (strings.length > 1) {
                    if (strings[1].contains("pence")) {
                        String[] fensStrArr = strings[1].split("pence");
                        fen = Double.parseDouble(fensStrArr[0]) / 123 * 100;
                    }
                }
                double val = yuan * 100 + fen;
                sum += val;
            }
        }
        System.out.println((int) sum);
    }

}
