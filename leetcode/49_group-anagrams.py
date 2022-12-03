"""

"""
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # 1. 딕셔너리 생성 a_1_e_1_t_1
        dictionary = {}
        for string in strs:
            if string == "":
                continue
            else:
                dict = {}
                for word in string:
                    if not (word in dict):
                        dict[word] = 1
                    else:
                        dict[word] = dict.get(word) + 1
                ## 정렬
                dict_sort = sorted(dict.items())
                ## print(dict_sort)

                key = ""
                for data in dict_sort:
                    if key == "" :
                        key += data[0]
                        key += "_"
                        key += str(data[1])
                    else :
                        key += "_"
                        key += data[0]
                        key += "_"
                        key += str(data[1])

                if not (key in dictionary):
                    dictionary[key] = string
                else:
                    new_str = dictionary[key]
                    new_str += " " + string
                    dictionary[key] = new_str
        # print(list(dictionary.items()))
        answer = []
        for data in dictionary.items():
            answer.append(data[1].split())

        if len(answer) == 0:
            answer.append([""])
        return answer
a = Solution()
# strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
strs = [""]
print(a.groupAnagrams(strs))