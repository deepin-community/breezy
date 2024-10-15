# Copyright (C) 2008, 2009, 2010 Canonical Ltd
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
#

"""Tests for chunks_to_lines."""

from .. import tests
from . import features


def load_tests(loader, standard_tests, pattern):
    suite, _ = tests.permute_tests_for_extension(
        standard_tests, loader, 'breezy._chunks_to_lines_py',
        'breezy._chunks_to_lines_pyx')
    return suite


# test_osutils depends on this feature being around. We can't just use the one
# generated by load_tests, because if we only load osutils but not this module,
# then that code never gets run
compiled_chunkstolines_feature = features.ModuleAvailableFeature(
    'breezy._chunks_to_lines_pyx')


class TestChunksToLines(tests.TestCase):

    module = None  # Filled in by test parameterization

    def assertChunksToLines(self, lines, chunks, alreadly_lines=False):
        result = self.module.chunks_to_lines(chunks)
        self.assertEqual(lines, result)
        if alreadly_lines:
            self.assertIs(chunks, result)

    def test_fulltext_chunk_to_lines(self):
        self.assertChunksToLines(
            [b'foo\n', b'bar\r\n', b'ba\rz\n'],
            [b'foo\nbar\r\nba\rz\n'])
        self.assertChunksToLines(
            [b'foobarbaz\n'], [b'foobarbaz\n'], alreadly_lines=True)
        self.assertChunksToLines(
            [b'foo\n', b'bar\n', b'\n', b'baz\n', b'\n', b'\n'],
            [b'foo\nbar\n\nbaz\n\n\n'])
        self.assertChunksToLines(
            [b'foobarbaz'], [b'foobarbaz'], alreadly_lines=True)
        self.assertChunksToLines([b'foobarbaz'], [b'foo', b'bar', b'baz'])

    def test_newlines(self):
        self.assertChunksToLines([b'\n'], [b'\n'], alreadly_lines=True)
        self.assertChunksToLines([b'\n'], [b'', b'\n', b''])
        self.assertChunksToLines([b'\n'], [b'\n', b''])
        self.assertChunksToLines([b'\n'], [b'', b'\n'])
        self.assertChunksToLines([b'\n', b'\n', b'\n'], [b'\n\n\n'])
        self.assertChunksToLines([b'\n', b'\n', b'\n'], [b'\n', b'\n', b'\n'],
                                 alreadly_lines=True)

    def test_lines_to_lines(self):
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz\n'],
                                 [b'foo\n', b'bar\r\n', b'ba\rz\n'],
                                 alreadly_lines=True)

    def test_no_final_newline(self):
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\nbar\r\nba\rz'])
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\n', b'bar\r\n', b'ba\rz'],
                                 alreadly_lines=True)
        self.assertChunksToLines((b'foo\n', b'bar\r\n', b'ba\rz'),
                                 (b'foo\n', b'bar\r\n', b'ba\rz'),
                                 alreadly_lines=True)
        self.assertChunksToLines([], [], alreadly_lines=True)
        self.assertChunksToLines([b'foobarbaz'], [b'foobarbaz'],
                                 alreadly_lines=True)
        self.assertChunksToLines([], [b''])

    def test_mixed(self):
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\n', b'bar\r\nba\r', b'z'])
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\nb', b'a', b'r\r\nba\r', b'z'])
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\nbar\r\nba', b'\r', b'z'])

        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz'],
                                 [b'foo\n', b'', b'bar\r\nba', b'\r', b'z'])
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz\n'],
                                 [b'foo\n', b'bar\r\n', b'ba\rz\n', b''])
        self.assertChunksToLines([b'foo\n', b'bar\r\n', b'ba\rz\n'],
                                 [b'foo\n', b'bar', b'\r\n', b'ba\rz\n'])

    def test_not_lines(self):
        # We should raise a TypeError, not crash
        self.assertRaises(TypeError, self.module.chunks_to_lines,
                          object())
        self.assertRaises(TypeError, self.module.chunks_to_lines,
                          [object()])
        self.assertRaises(TypeError, self.module.chunks_to_lines,
                          [b'foo', object()])