from flask import Flask, jsonify, render_template, make_response
from flask_cors import CORS, cross_origin

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'


@app.route('/api/get')
@cross_origin()
def getData():
    file = open('./static/data/data.txt', 'r')
    re = file.read()
    temp = re.split('\n')[-2]
    d = dict(map(lambda x: x.split(':'), temp.split(',')))
    return jsonify(d)


@app.route('/')
@app.route('/dashboard')
@cross_origin()
def index():
    resp = make_response(render_template('dashboard.html', active_page="home"))
    resp.headers['X-Content-Type-Options'] = 'nosniff'
    return resp


@app.route('/circuit')
def components():
    return render_template('circuit.html', active_page="circuit")


if __name__ == "__main__":
    app.run(debug=True)