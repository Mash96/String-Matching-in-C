/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author madhavadabare
 */
public class KMP {

    static int[] prefixFn(String pattern) {
        String P[] = pattern.split("");
        int pi[] = new int[P.length];

        int k = 0;
        pi[0] = k;
        for (int q = 1; q < pi.length; q++) {
            while (k > 0 && !P[k].equals(P[q])) {
                k = pi[k];
            }
            if (P[k].equals(P[q])) {
                k++;
            }
            pi[q] = k;
        }

        return pi;
    }

    static int[] prefixFn(char[] pattern) {
        int pi[] = new int[pattern.length];

        int k = 0;
        pi[0] = k;
        for (int q = 1; q < pi.length; q++) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }

        return pi;
    }

    static String KMP(String text, String pattern) {
        String result = "";
        int pi[] = prefixFn(pattern);
        String[] P = pattern.split(""), T = text.split("");
        int q = 0;

        for (int i = 0; i < T.length; i++) {
            while (q > 0 && !P[q].equals(T[i])) {
                q = pi[q];
            }
            if (P[q].equals(T[i])) {
                q++;
            }
            if (q == P.length) {
                result += i - P.length + 1 + " ";
                q = pi[q - 1];
            }
        }

        return result;
    }

    static int[] preProcessPattern(char[] ptrn) {
        int i = 0, j = -1;
        int ptrnLen = ptrn.length;
        int[] b = new int[ptrnLen + 1];

        b[i] = j;
        while (i < ptrnLen) {
            while (j >= 0 && ptrn[i] != ptrn[j]) {
                j = b[j];
            }
            i++;
            j++;
            b[i] = j;
        }
        return b;
    }

    static String searchSubString(String T, String P) {
        String result = "";
        char[] text = T.toCharArray(), ptrn = P.toCharArray();

        int i = 0, j = 0;
        int ptrnLen = ptrn.length;
        int txtLen = text.length;

        int[] b = preProcessPattern(ptrn);

        while (i < txtLen) {
            while (j >= 0 && text[i] != ptrn[j]) {
                j = b[j];
            }
            i++;
            j++;

            if (j == ptrnLen) {
                result += i - ptrnLen + " ";
                j = b[j];
            }
        }
        return result;
    }
}
