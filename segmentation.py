import json


def segmenter(json_string):
	string_dict = json.loads(json_string)
	original_string = string_dict["sentences"][0]["text"]["content"]
	print(original_string)
	for i in range(0, len(string_dict["tokens"])):
		parent = int(string_dict["tokens"][i]["dependencyEdge"]["headTokenIndex"])

		print(string_dict["tokens"][i]["text"]["content"] +" " + string_dict["tokens"][parent]["text"]["content"])
	return string_dict


fname = "tmp.txt"
text = open(fname).read()

segmenter(text)