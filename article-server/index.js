const express = require('express')
const app = express()
const port = process.argv[2]
const read = require('node-readability')

app.get('/article', (req, res) => {
      read(req.query.url, function(err, article, meta) {
          const body = article.textBody;
          res.send(body);
        });
})

app.listen(port, () => console.log(`Article server running on port ${port}!`))
