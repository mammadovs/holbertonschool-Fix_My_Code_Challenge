#!/usr/bin/env ruby

results = ARGV.map { |arg| arg.to_i }.sort
results.each { |result| puts result }

