import json


def segmenter(json_string):
	string_dict = json.loads(json_string)
	print(string_dict["sentences"][0]["text"])
	print(string_dict["tokens"][0]["text"])
	return string_dict


fname = "tmp.txt"
text = open(fname).read()

segmenter(text)