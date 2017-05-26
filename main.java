/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author madhavadabare
 */
public class main {
    public static void main(String[] args) {
        String p = "abcabdabc", t = "abcabdabcabdabcabdabdabc";
        
        System.out.println(Naive.NSM(t, p));
        System.out.println(RabinCarp.RabinCarp(t, p, 100, 13));
    }
}
