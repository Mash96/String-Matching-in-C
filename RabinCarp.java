/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author madhavadabare
 */
public class RabinCarp {

    static String RabinCarp(String text, String pattern, int d, int q) {
        String result = "";

        char P[] = pattern.toCharArray();
        char T[] = text.toCharArray();

        int M = P.length;
        int N = T.length;
        int i, j;
        int p = 0; // hash value for pattern
        int t = 0; // hash value for txt
        int h = 1;

        // The value of h would be "pow(d, M-1)%q"
        for (i = 0; i < M - 1; i++) {
            h = (h * d) % q;
        }

        // Calculate the hash value of pattern and first
        // window of text
        for (i = 0; i < M; i++) {
            p = (d * p + P[i]) % q;
            t = (d * t + T[i]) % q;
        }

        // Slide the pattern over text one by one
        for (i = 0; i <= N - M; i++) {

            // Check the hash values of current window of text
            // and pattern. If the hash values match then only
            // check for characters on by one
            if (p == t) {
                /* Check for characters one by one */
                for (j = 0; j < M; j++) {
                    if (T[i + j] != P[j]) {
                        break;
                    }
                }

                // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
                if (j == M) {
                    result += i + " ";
                }
            }

            // Calculate hash value for next window of text: Remove
            // leading digit, add trailing digit
            if (i < N - M) {
                t = (d * (t - T[i] * h) + T[i + M]) % q;

                // We might get negative value of t, converting it
                // to positive
                if (t < 0) {
                    t = (t + q);
                }
            }
        }
        return result;
    }

}
