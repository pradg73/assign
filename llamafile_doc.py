from openai import OpenAI
import re

def client():
    client = OpenAI(
        base_url="http://localhost:8083/v1", # "http://<Your api-server IP>:port"
        api_key = "sk-no-key-required"
    )
    return client

def extract_code(text):
    pattern = r'(?s).*?```(.*?)```.*?$'

    match = re.search(pattern, text, re.DOTALL)
    if match:
        return match.group(1).strip()
    return None

def run_doc(client, code):
    completion = client.chat.completions.create(
        model="LLaMA_CPP",
        messages=[
            {"role": "system", "content": "You are an expert Python programmer and technical writer. Your task is to provide clear and comprehensive documentation for Python code."},
            {"role": "user", "content": f"Please document the following Python code. Write file, class and method level docstrings. Output Python code with docstrings. Do not add any new code or change the existing code. Output Python code only , without any additional tokens or decorations:\n\n{code}"}
        ]
    )
    return completion.choices[0].message.content

# write an openai api compatible prompt that takes some code and generates unit test cases
def generate_unit_tests(client, code):
    completion = client.chat.completions.create(
        model="LLaMA_CPP",
        messages=[
            {"role": "system", "content": "You are an expert Python programmer specializing in writing comprehensive unit tests. Your task is to generate unit test cases for given Python code."},
            {"role": "user", "content": f"Please generate unit test cases for the following Python code. Include tests for different scenarios, edge cases, and potential errors. use pytest framework. generate python code only without any explaination of your actions.Output Python code only , without any additional tokens or decorations:\n\n{code}"}
        ]
    )
    return completion.choices[0].message.content

import sys
#write a main function
def main(argv=None):
    if argv is None:
        argv = sys.argv[1:]
    
    # open a file 
    with open(argv[0], 'r') as file:
        code = file.read()
    client_instance = client()
    result = run_doc(client_instance, code)
    result = extract_code(result)
    #write result to a file, if not provided, write to a file named argv[0]_doc.py
    if len(argv) > 1:
        with open(argv[1], 'w') as file:
            file.write(result)
    else:
        with open(argv[0] + "_doc.py", 'w') as file:
            file.write(result)
    result = generate_unit_tests(client_instance, code)
    result = extract_code(result)
    with open(argv[0] + "_test.py", 'w') as file:
        file.write(result)
    print("done")
if __name__ == "__main__":
    main()

