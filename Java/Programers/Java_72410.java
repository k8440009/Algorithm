// import java.util.ArrayList;

// public class Java_72410 {
//     public static void main(String[] args) {
//         String str = "123_.def";

//         Solution test = new Solution();
//         System.out.println(test.solution(str));

//     }
// }

// class Solution {
//     public String solution(String new_id) {
//         StringBuilder sb = new StringBuilder();
//         ArrayList<String> arrayList = new ArrayList<String>();
//         if (new_id.length() > 0) {
//             String[] tokens = new_id.toLowerCase().split("");
//             // 1.
//             for (String token : tokens) {
//                 char c = token.charAt(0);
//                 if ((c >= 'a' && c <= 'z')
//                         || (c >= '0' && c <= '9')
//                         || c == '-' || c == '_' || c == '.') {
//                     arrayList.add(token);
//                 }

//                 if (arrayList.size() >= 2) {
//                     int nowIndex = arrayList.size() - 1;
//                     int bfIndex = arrayList.size() - 2;
//                     if (c == '.' && ".".equals(arrayList.get(bfIndex))) {
//                         arrayList.remove(nowIndex);
//                     }
//                 }
//             }
//         }

//         if (arrayList.size() >= 1) {
//             if (arrayList.size() == 1) {
//                 if (".".equals(arrayList.get(0))) {
//                     arrayList.remove(0);
//                 }
//             } else {
//                 int stIdx = 0;
//                 int edIdx = arrayList.size() - 1;

//                 if (".".equals(arrayList.get(edIdx))) {
//                     arrayList.remove(edIdx);
//                 }

//                 if (".".equals(arrayList.get(stIdx))) {
//                     arrayList.remove(stIdx);
//                 }
//             }
//         }

//         if (arrayList.size() == 0) {
//             arrayList.add("a");
//         }

//         if (arrayList.size() >= 16) {
//             for (int i = 0; i < 14; i++) {
//                 sb.append(arrayList.get(i));
//             }

//             if (".".equals(arrayList.get(14)) == false) {
//                 sb.append(arrayList.get(14));
//             }
//         } else if (arrayList.size() <= 2) {
//             int edIdx = arrayList.size() - 1;
//             for (int i = 0; i < arrayList.size(); i++) {
//                 sb.append(arrayList.get(i));
//             }

//             if (arrayList.size() == 1) {
//                 sb.append(arrayList.get(edIdx));
//                 sb.append(arrayList.get(edIdx));
//             } else {
//                 sb.append(arrayList.get(edIdx));
//             }
//         } else {
//             for (int i = 0; i < arrayList.size(); i++) {
//                 sb.append(arrayList.get(i));
//             }
//         }

//         return sb.toString();
//     }
// }