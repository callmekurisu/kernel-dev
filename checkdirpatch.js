'use strict'
// place this file in kernel 'scripts' directory
const pfs = require('fs').promises
const { spawn } = require('child_process')
const dir = process.argv[2]
const lvl = process.argv[3]
const path = `./${dir}`
const checkPatch = './scripts/checkpatch.pl -f'
const badInput = dir === undefined || dir === null || dir === ''
                || lvl === undefined || lvl === null || lvl === ''

/**
 * Check for valid command line arguments
 */
if(badInput) {
    console.log('Run checkpatch.pl on directories')
    console.log('Usage: node ./scripts/checkdirpatch <path/to/check>'
    + ' <LEVEL> (e.g. WARNING or ERROR)')
    process.exit(1)
} else {
    console.log(`Reading path ${path}...`)
}

/**
 * Async function for running checkpatch.pl on entire directory
 * We won't drill down any further from here and only check for
 * files at the current directory. Output is controlled via the 
 * log level which is passed as command line argument
 */
async function check() {
    const files = await pfs.readdir(path).then(v => v)
    files.forEach(async f => {
        const stat = await pfs.lstat(`${path}${f}`)
        if(stat.isFile()) {
            const child = spawn(`${checkPatch} ${path}${f} | grep -A1 ${lvl}`, {
                shell: true,
                stdio: ['pipe', 'inherit', 'ignore']
            })
        }
    })
}
check().catch(e => console.error(e))
