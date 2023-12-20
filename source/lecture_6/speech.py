# Says hello to someone

# `pyttsx3` is a Python library that provides a simple way to interact with text-to-speech
# engines. In this code, it is being used to convert the text "hello, {name}" into speech.
import pyttsx3

engine = pyttsx3.init()
name = input("What's your name? ")
engine.say(f"hello, {name}")
engine.runAndWait()
engine.say("This was CS50")
engine.runAndWait()
