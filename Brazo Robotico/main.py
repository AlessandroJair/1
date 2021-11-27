import serial
import time

from flask import Flask, render_template, request


app = Flask(__name__)  # flask init

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600)


@app.route("/")
def root():
    return render_template("test1.html")


@app.route("/set", methods=["POST"])
def setangles():
    form = request.form

    for k, v in form.items():
        send = f"{k}:{v}\n"
        print(send)
        ser.write(send.encode())
        ser.flush()
        time.sleep(0.4)
    return "ok"


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=6969, debug=True, threaded=True)
