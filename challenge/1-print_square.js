#!/usr/bin/node

const size = parseInt(process.argv[2]);

if (size) {
    for (let i = 0; i < size; i++) {
        let row = '';
        for (let j = 0; j < size; j++) {
            row += '#';
        }
        console.log(row);
    }
}

