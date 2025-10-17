from openai import OpenAI
import os
from dotenv import load_dotenv

load_dotenv(dotenv_path='/Users/sebastian/Repositories/Github/Raylibs/DnD_Game/.env')
client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

response = client.responses.create(
    model="gpt-5",
    input="Write a one-sentence bedtime story about a unicorn."
)

historie = []

def chatToAI(inputFromUser):
    response = client.responses.create(
    model="gpt-5",
    input=inputFromUser
    )
    historie.append(response.output_text)
    return response

#print(chatToAI("hei på deg").output_text)

while True:
    melding = chatToAI(input("Your message: "))
    print(melding.output_text)
    print("-"*20)
    print(historie)
